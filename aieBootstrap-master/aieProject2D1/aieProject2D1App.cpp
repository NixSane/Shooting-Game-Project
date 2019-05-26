#include "aieProject2D1App.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "bullet.h"
#include "Enemy.h"
#include "game_objects.h"
#include "defines.h"
#include <iostream>
#include <random>
#include <ctime>
#include "button.h"


aieProject2D1App::aieProject2D1App() {

}

aieProject2D1App::~aieProject2D1App() {

}

bool aieProject2D1App::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	
	m_background = new aie::Texture("./textures/background.png");
	m_world_track = new aie::Texture("./textures/bg_world_track.png");
	m_faceTexture = new aie::Texture("./textures/Face.png");

	// Game Objects that are part of gameplay
	m_player = new player();
	m_player->set_position(640.0f, 360.0f);
	
	// Button
	m_button = new button("Spawn", 100, 680, 120, 50);

	// Bar | (left to right, bottom to top, width, height)
	m_bar = new Bar(300, 690, 200, 20);
	float health = 100;

	m_bar->set_value(health);

	m_timer = 0;

	// Waves
	m_wave = 1;
	m_spawn_increase = 10;
	m_wave_enemies = m_wave * m_spawn_increase;
	m_spawned_enemies = 0;
	m_enemy_cap = 200;
	m_spawn_timer = 0;

	srand(time(NULL));

	return true;
}

void aieProject2D1App::shutdown() 
{
	delete m_button;
	delete m_font;
	delete m_2dRenderer;
	delete m_world_track;
	delete m_player;
	delete m_background;
	delete m_faceTexture;
}

void aieProject2D1App::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	// Player
	m_player->update(deltaTime);

	if (m_player->is_shooting())
	{
		m_projectile.push_back(new bullet(m_player->get_position_x(), m_player->get_position_y(), m_player->get_rotation(), 500.0f));
	}

	// Bullets
	for (std::list<bullet*>::iterator iter = m_projectile.begin(); iter != m_projectile.end(); )
	{
		bullet* a_bullet = *iter;

		a_bullet->update(deltaTime);

		for (std::list<Enemy*>::iterator e_iter = m_enemy.begin(); e_iter != m_enemy.end(); e_iter++)
		{
			Enemy *enemy = *e_iter;
			if (enemy->is_alive()) 
			{
				if (a_bullet->is_colliding(enemy))
				{
					a_bullet->set_alive(false);
					enemy->set_alive(false);
				}
			}
		}

		if (!a_bullet->is_alive())
		{
			delete a_bullet;
			iter = m_projectile.erase(iter);
		}
		else
		{
			iter++;
		}

	}
	// Ship

	// Enemy Update
	for (std::list<Enemy*>::iterator iter = m_enemy.begin(); iter != m_enemy.end(); iter++)
	{
		Enemy *enemy = *iter;

		if (enemy->is_alive())
		{
			enemy->update(deltaTime);

			if (enemy->is_colliding(m_player))
			{
				float health = m_player->damage(5);
				m_bar->set_value(health);
				if (health == 0)
				{
					m_player->set_alive(false);
				}
			}

			if (!enemy->is_alive())
			{
				delete enemy;
				iter = m_enemy.erase(iter);
			}
		}
	}

	if (!m_player->is_alive())
	{
		quit();
	}
	

	//================================
	// Spawning for Enemies
	//================================
		
	if (m_button->Update())
	{
		int y_pos = MIN_Y_SPAWN + (rand() % (MAX_Y_SPAWN - MIN_Y_SPAWN));
		m_enemy.push_front(new Enemy(1300.0f, y_pos, 100.0f));
	}
		
	m_player->update(deltaTime);
	
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void aieProject2D1App::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	

	// Enemy
	for (std::list<Enemy*>::iterator e_iter = m_enemy.begin(); e_iter != m_enemy.end(); e_iter++)
	{
		Enemy *enemy = *e_iter;
		if(enemy->is_alive())
		(*e_iter)->draw(m_2dRenderer);
	}

	// Draw Text
	if (!m_player->is_alive())
	{
		m_2dRenderer->drawText(m_font, "Game Over Press enter to continue", 340, 360);
	}

	// Button
	m_button->Draw(m_2dRenderer);
	
	// Bullets
	for (std::list<bullet*>::iterator iter = m_projectile.begin(); iter != m_projectile.end(); iter++)
	{
		bullet *bull = *iter;
		if (bull->is_alive())
		(*iter)->draw(m_2dRenderer);
	}

	// Bar
	m_bar->Draw(m_2dRenderer);

	// Background
	m_2dRenderer->drawSprite(m_world_track, 0, 0, 1280, 720, 0, 100, 0, 0); 

	// Sprite
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_player->draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}