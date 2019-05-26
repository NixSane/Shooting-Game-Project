#include "bullet.h"

bullet::bullet(float a_pos_x, float a_pos_y, float a_aim, float a_velocity) : game_objects("./textures/bullet.png")
{	
	m_position_x = a_pos_x;
	m_position_y = a_pos_y;
	m_rotation = a_aim;
	m_velocity = a_velocity;
	m_radius = 10.0f;
}

bullet::~bullet()
{
}

void bullet::update(float deltaTime)
{
	m_distance = m_velocity;

	/*if (m_position_x < 0) {
		m_is_alive = false;
	}

	if (m_position_x > 1280) {
		m_is_alive = false;
	}

	if (m_position_y < 0) {
		m_is_alive = false;
	}

	if (m_position_y < 720) {
		m_is_alive = false;
	}*/

	game_objects::update(deltaTime);
}

void bullet::draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawSprite(m_texture, m_position_x, m_position_y, 20.0f, 20.0f, m_rotation, 0, 0.5f, 0.5f);
}






