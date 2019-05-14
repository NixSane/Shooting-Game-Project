#include "Enemy.h"



Enemy::Enemy(float a_pos_x, float a_pos_y, float a_velocity, aie::Texture* a_texture)
{
	e_pos_x = a_pos_x;
	e_pos_y = a_pos_y;
	m_velocity = a_velocity;

	m_enemy_texture = a_texture;
	e_alive = true;
}


Enemy::~Enemy()
{
}

void Enemy::update(float deltaTime)
{
		e_pos_x += -m_velocity * deltaTime;
}

void Enemy::draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawSprite(m_enemy_texture, e_pos_x, e_pos_y, 0, 0, 0, 0, 0.5f, 0.5f);
}

bool Enemy::is_alive()
{
	return e_alive;
}
