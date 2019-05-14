#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "game_objects.h"
#include "button.h"
#include "Bar.h"
#include <list>

class player;
class bullet;
class Enemy;

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

	float bullet_x = 0;
	float bullet_y = 0;
	float bullet_rot = 0;

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

	player*				m_player;
	std::list<bullet*>	m_projectile;
	std::list<Enemy*>	m_enemy;

	button*				m_button;

	Bar*				m_bar;

	unsigned int m_wave, m_wave_enemies, m_spawned_enemies, m_enemy_cap, m_spawn_increase;
	
	float m_timer;
	float  m_spawn_timer;
};