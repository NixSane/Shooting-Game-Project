#include "aieProject2D1App.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "bullet.h"


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

	m_player = new game_objects(m_ship);
	m_projectile = new game_objects(m_bullet);

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
}

void aieProject2D1App::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	// Ship movement numbers
	float player_x = m_player->get_position_x();
	float player_y = m_player->get_position_y();
	float player_rot = m_player->get_rotation();


	// For now
	float player_speed = 400.0f;
	float bullet_speed = 800.0f;

	// Bullet conditions
	bool is_shooting = false;
	float cooldown = 0.0f;
	cooldown += deltaTime;
	float delay = 0.2f;

	float bullet_x = player_x;
	float bullet_y = player_y;
	float bullet_rot = player_rot;


	const float pi = 3.14158f;

	// Direction inputs
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		player_x += cos(-player_rot - pi * 0.5f) * player_speed * deltaTime;
		player_y += -sin(-player_rot - pi * 0.5f) * player_speed * deltaTime;
	}
	
	if (input->isKeyDown(aie::INPUT_KEY_S) && speed > 0)
	{
		player_x -= cos(-player_rot - pi * 0.5) * player_speed * deltaTime;
		player_y -= -sin(-player_rot - pi * 0.5) * player_speed * deltaTime;
	}
	

	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		player_rot += pi * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		player_rot += -pi * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && cooldown > delay)
	{
		is_shooting = true;
		{
			m_projectile->set_position(bullet_x, bullet_y);
			m_projectile->set_rotation(bullet_rot);
		}
	}
	else
	{
		is_shooting = false;
	}


	m_player->set_position(player_x, player_y);
	m_player->set_rotation(player_rot);
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void aieProject2D1App::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!

	// Background
	m_2dRenderer->drawSprite(m_world_track, 0, 0, 1280, 720, 0, 100, 0, 0); 

	// Sprite
	m_2dRenderer->setUVRect(0, 0, 1, 1);

	m_player->draw(m_2dRenderer);
	//m_2dRenderer->drawSprite(m_ship, x, y, 127, 130, rotation, 0, 0.5f, 0.3f);
	
	/* m_2dRenderer->drawLine(100, 100, 200, 200, 5, 5); */
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}