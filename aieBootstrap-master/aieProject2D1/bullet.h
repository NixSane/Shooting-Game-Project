#pragma once
#include "game_objects.h"
#include "player.h"



class bullet 
{
public:
	bullet(float a_pos_x, float a_pos_y, float a_aim, float a_velocity, aie::Texture* a_texture);
	~bullet();

	void update(float deltaTime);
	void draw(aie::Renderer2D* a_renderer);

private:
	aie::Texture* m_bullet_texture;

	float b_pos_x;
	float b_pos_y;
	float m_aim;
	float m_velocity;
};

