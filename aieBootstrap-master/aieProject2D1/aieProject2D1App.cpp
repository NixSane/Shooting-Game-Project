#include "aieProject2D1App.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "bullet.h"
#include <iostream>


aieProject2D1App::aieProject2D1App() {

}

aieProject2D1App::~aieProject2D1App() {

}

bool aieProject2D1App::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_faceTexture = new aie::Texture("./textures/car2.png");
	m_background = new aie::Texture("./textures/background.png");
	m_sunny_road = new aie::Texture("./textures/background_sunny.png");
	m_world_track = new aie::Texture("./textures/bg_world_track.png");
	m_ship = new aie::Texture("./textures/ship_2 - Copy.png");
	m_bullet = new aie::Texture("./textures/bullet.png");

	// Game Objects that are part of gameplay
	m_player = new player("./textures/ship_2 - Copy.png", 640.0f, 360.0f, 0.0f, 200.0f);

	// Button
	m_button = new button("Pause", 1180, 680, 120, 50);

	// Bar | (left to right, bottom to top, width, height)
	m_bar = new Bar(140, 690, 200, 20);

	m_timer = 0;

	return true;
}

void aieProject2D1App::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_faceTexture;
	delete m_ship;
	delete m_world_track;
	delete m_bullet;
	delete m_button;
	delete m_bar;
	delete m_player;
}

void aieProject2D1App::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	// Ship
	m_player->update(deltaTime);

	if (m_player->is_shooting())
	{
		m_projectile.push_back(new bullet(m_player->get_pos_x(), m_player->get_pos_y(), m_player->get_rot(), 500.0f, m_bullet));
	}
	for (std::list<bullet*>::iterator iter = m_projectile.begin(); iter != m_projectile.end(); iter++)
	{
		(*iter)->update(deltaTime);
	}
	

	// Ship

	// Button inputs
	if (m_button->Update())
	{
		// Replace this with whatever the button should do
		std::cout << "Button clicked" << std::endl;
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

	// Buttons
	m_button->Draw(m_2dRenderer);

	// Bars
	m_bar->Draw(m_2dRenderer);

	// Bullets
	// Bullets
	for (std::list<bullet*>::iterator iter = m_projectile.begin(); iter != m_projectile.end(); iter++)
	{
		(*iter)->draw(m_2dRenderer);
	}

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