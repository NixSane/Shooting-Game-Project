#include "player.h"



player::player()
{
	// Default
	m_speed = 400;
}


player::~player()
{
}

void player::set_speed(float a_speed)
{
	m_speed = a_speed;
}

float player::get_speed() const
{
	return m_speed;
}


