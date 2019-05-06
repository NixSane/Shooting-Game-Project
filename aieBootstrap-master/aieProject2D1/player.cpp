#include "player.h"



player::player()
{
	// Default
	m_speed = 0;
	m_lives = 5;
}

player::player(float a_speed, int a_lives) :
	m_speed(a_speed), m_lives(a_lives)
{
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

void player::set_lives(int a_lives)
{
	m_lives = a_lives;
}

int player::get_lives() const
{
	return m_lives;
}