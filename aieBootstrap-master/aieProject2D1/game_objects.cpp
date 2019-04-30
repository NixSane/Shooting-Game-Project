#include "game_objects.h"
#include "Renderer2D.h"


game_objects::game_objects()
{
}


game_objects::~game_objects()
{
}

			// Setters //

void game_objects::set_speed(float a_speed)
{
	speed = a_speed;
}

void game_objects::set_rotation(float a_rot)
{
	rotation = a_rot;
}

void game_objects::set_position(float a_x, float a_y)
{
	position_x = a_x;
	position_y = a_y;
}

void game_objects::set_radius(float a_radius)
{
	m_radius = a_radius;
}


			// Getters //

float game_objects::get_speed() const
{
	return speed;
}

float game_objects::get_rotation() const
{
	return rotation;
}

float game_objects::get_position() const
{
	return position_x, position_y;
}

float game_objects::get_radius() const
{
	return m_radius;
}


