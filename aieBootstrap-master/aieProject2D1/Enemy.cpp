#include "Enemy.h"



Enemy::Enemy(float a_pos_x, float a_pos_y, float a_velocity) : game_objects("./textures/Face.png")
{
	m_position_x = a_pos_x;
	m_position_y = a_pos_y;
	m_velocity = a_velocity;
	m_rotation = 180.0f;
}


Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
	m_distance = -m_velocity;
	m_rotation = 4.9f;

	game_objects::update(deltaTime);
}

void Enemy::draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawSprite(m_texture, m_position_x, m_position_y, 0, 0, 0, 0, 0.5f, 0.5f);
}
