#pragma once
#include "game_objects.h"
#include "bullet.h"


class player
{
public:
	player(const char* a_text, float a_pos_x, float a_pos_y, float a_rot, float a_speed);
	~player();

	void update(float deltaTime);
	void draw(aie::Renderer2D* a_renderer);

	float get_pos() const;
	float get_pos_x() const;
	float get_pos_y() const;
	float get_rot() const;

	bool is_shooting()
	{
		return m_is_shooting;
	}

private:

	aie::Texture* m_texture_ship;

	float m_position_x;
	float m_position_y;
	float m_rotation;
	float m_speed;
	float pi;
	float m_radius;

	bool m_is_shooting;
	float m_cooldown;
};

