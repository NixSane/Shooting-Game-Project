#pragma once
#include "game_objects.h"

class player : public game_objects
{
public:
	player();
	~player();


	void update(float deltaTime);

	bool is_shooting()
	{
		return m_is_shooting;
	}

	float damage(float atk);
	void draw(aie::Renderer2D* a_renderer);

private:

	
	float m_speed;
	float pi;
	float m_radius;
	float m_health;

	bool m_is_shooting;
	float m_cooldown;
};

