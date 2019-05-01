#include "game_objects.h"
#include "Renderer2D.h"
#include "Texture.h"

game_objects::game_objects(aie::Texture* const a_texture)
{
	m_texture = a_texture;
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

void game_objects::set_radius(float a_radius)
{
	m_radius = a_radius;
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

float game_objects::get_radius() const
{
	return m_radius;
}

void game_objects::draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawSprite(m_texture, m_position_x, m_position_y, 0, 0, m_rotation, 0, 0.5f, 0.5f);
	a_renderer->drawCircle(m_position_x, m_position_y, m_radius, 0);
}

