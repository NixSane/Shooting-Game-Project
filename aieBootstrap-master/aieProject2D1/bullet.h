#pragma once
#include "game_objects.h"
#include "player.h"



class bullet : public game_objects
{
public:
	bullet(float a_pos_x, float a_pos_y, float a_aim, float a_velocity);
	~bullet();

	void update(float deltaTime);
	void draw(aie::Renderer2D* a_renderer);


private:
	
	unsigned int m_damage;
	float m_velocity;
};

