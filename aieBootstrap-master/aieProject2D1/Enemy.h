#pragma once
#include "game_objects.h"
#include "Defines.h"
#include "bullet.h"

class Enemy
{
public:
	Enemy(float a_pos_x, float a_pos_y, float a_velocity, aie::Texture* a_texture);
	~Enemy();

	void draw(aie::Renderer2D* a_renderer);
	void update(float deltaTime);

	bool is_alive();


private:
	aie::Texture* m_enemy_texture;

	float e_pos_x;
	float e_pos_y;
	float m_velocity;
	bool e_alive;
};

