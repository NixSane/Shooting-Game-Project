#pragma once
#include "game_objects.h"
#include "bullet.h"

class player
{
public:
	player();
	~player();


	void set_speed(float a_speed);

	float get_speed() const;

private:
	float m_speed = 0.0f;
};

