#include "game_objects.h"


game_objects::game_objects(const char* a_texture)
{
	m_texture = new aie::Texture(a_texture);
	m_rotation = 0;
	m_distance = 0;
	m_pi = 0;
	m_radius = 0;
	m_is_alive = true;
}


			// Setters //

void game_objects::set_rotation(float a_rot)
{
	m_rotation = a_rot;
}

void game_objects::set_position(float a_x, float a_y)
{
	m_position_x = a_x;
	m_position_y = a_y;
}


void game_objects::set_speed(float a_speed) 
{
	m_distance = a_speed;
}

void game_objects::set_alive(bool state)
{
	m_is_alive = state;
}

			// Getters //

float game_objects::get_rotation() const
{
	return m_rotation;
}

float game_objects::get_position_x() const
{
	return m_position_x;
}

float game_objects::get_position_y() const
{
	return  m_position_y;
}

float game_objects::get_radius()
{
	m_radius = m_texture->getWidth() * 0.5f;
	return m_radius;
}

float game_objects::get_speed() const
{
	return m_distance;
}

void game_objects::update(float deltaTime)
{
 
	float s = sinf(m_rotation) * m_distance;
	float c = cosf(m_rotation) * m_distance;
	m_position_x -= s * deltaTime;
	m_position_y += c * deltaTime;
}

void game_objects::draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawSprite(m_texture, m_position_x, m_position_y, 0, 0, m_rotation, 0, 0.5f, 0.5f);
	a_renderer->drawCircle(m_position_x, m_position_y, m_radius, 0);
}

bool game_objects::is_colliding(game_objects* other)
{
	float distance =
		sqrt((m_position_x - other->get_position_x()) *
			(m_position_x - other->get_position_x()) +
			((m_position_y - other->get_position_y()) *
			(m_position_y - other->get_position_y())));

	if (distance < m_radius + other->get_radius())
	{
		return true;
	}
	return false;
}

