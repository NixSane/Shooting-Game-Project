#include "bullet.h"



bullet::bullet()
{
	// Default
	m_delay = 20.0f;
	m_is_shooting = false;
	
}

bullet::bullet(bool a_shoot, float a_delay) :
	m_is_shooting(a_shoot), m_delay(a_delay)
{
}

bullet::~bullet()
{
}

void bullet::set_shooting(bool a_shooting)
{
	m_is_shooting = a_shooting;
}


void bullet::set_delay(float a_delay)
{
	m_delay = a_delay;
}


float bullet::get_delay() const
{
	return m_delay;
}

bool bullet::get_shooting() const
{
	return m_is_shooting;
}