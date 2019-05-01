#include "bullet.h"



bullet::bullet()
{
	// Default
	m_delay = 20.0f;
	m_is_shooting = false;
	m_cooldown = 5.0f;
}

bullet::bullet(bool a_shoot, float a_delay, float a_cooldown) :
	m_is_shooting(a_shoot), m_delay(a_delay), m_cooldown(a_cooldown)
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

void bullet::set_cooldown(float a_cooldown)
{
	m_cooldown = a_cooldown;
}

float bullet::get_cooldown() const
{
	return m_cooldown;
}

float bullet::get_delay() const
{
	return m_delay;
}

bool bullet::get_shooting() const
{
	return m_is_shooting;
}