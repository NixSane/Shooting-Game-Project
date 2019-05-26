#pragma once
#include "game_objects.h"

class Enemy : public game_objects
{
public:
	Enemy(float a_pos_x, float a_pos_y, float a_velocity);
	~Enemy();

	void draw(aie::Renderer2D* a_renderer);
	void update(float deltaTime);

private:
	
	float m_velocity;
	
};

