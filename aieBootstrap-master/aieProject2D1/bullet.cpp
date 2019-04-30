#include "bullet.h"



bullet::bullet()
{
	// Default
	
	m_delay = 20.0f;
	is_shooting = false;
	m_cooldown = 5.0f;
}

bullet::bullet(bool a_shoot, float a_delay, float delay, float a_cooldown) :
	is_shooting(a_shoot), m_delay(a_delay), m_cooldown(a_cooldown)
{
	// Default
	
	m_delay = a_delay;
	is_shooting = a_shoot;
	m_cooldown = a_cooldown;
}

bullet::~bullet()
{
}

void bullet::set_shooting(bool a_shooting)
{
	is_shooting = a_shooting;
}


void bullet::set_delay(float a_delay)
{
	m_delay = a_delay;
}

void bullet::set_cooldown(float a_cooldown)
{
	m_cooldown = a_cooldown;
}