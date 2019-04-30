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

	/*m_timer += deltaTime;*/

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	// Ship rotation
	float s = sinf(rotation) * speed;
	float c = cosf(rotation) * speed;
	x -= s * deltaTime;
	y += c * deltaTime;
	
	// Bullet spawn
	m_projectile = new bullet::bullet();

	

	// Direction inputs
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		while (speed < 500)
		{
			speed += 30;
			if (speed > 500)
			{
				speed = 500;
			}
		}
	}
	else if (speed > 0)
	{
		speed -= 5;
		if (speed < 0)
		{
			speed = 0;
		}
	}

	if (input->isKeyDown(aie::INPUT_KEY_S) && speed > 0)
	{
			speed -= 20;
			if (speed < 0)
			{
				speed = 0;
			}
	}
	

	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		rotation += 0.05f;
	}

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		rotation -= 0.05f;
	}

	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && m_delay > cooldown)
	{
		is_shooting = true;
		if (is_shooting)
		{
			
		}
	}

	/*m_2dRenderer->setCameraPos(cam_posX, cam_posY);*/
	
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
	m_2dRenderer->drawSprite(m_world_track, 0, 0, 1280, 720, 0, 50, 0, 0); 

	// Sprite
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_ship, x, y, 127, 130, 0, rotation, 0.5f, 0.3f);
	//m_2dRenderer->drawSpriteTransformed3x3(m_faceTexture, 3.0f, playerPosX, playerPosY, 36, 42, 0, 0, 0, 0);


	/* m_2dRenderer->drawLine(100, 100, 200, 200, 5, 5); */
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}