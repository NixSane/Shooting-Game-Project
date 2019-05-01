#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "game_objects.h"

class aieProject2D1App : public aie::Application {
public:

	aieProject2D1App();
	virtual ~aieProject2D1App();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	float playerPosX = 640;
	float playerPosY = 360;

	float x = 640.0f, y = 360.0f;
	float rotation = 0;
	float speed = 0;
	

protected:

	aie::Texture*		m_faceTexture;
	aie::Texture*		m_ship;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_background;
	aie::Texture*		m_sunny_road;
	aie::Texture*		m_world_track;
	aie::Texture*		m_bullet;

	game_objects*		m_player;
	game_objects*		m_projectile;
	
	float m_timer;
};