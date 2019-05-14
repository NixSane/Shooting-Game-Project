#include "bullet.h"

bullet::bullet(float a_pos_x, float a_pos_y, float a_aim, float a_velocity, aie::Texture* a_texture)
{	
	b_pos_x = a_pos_x;
	b_pos_y = a_pos_y;
	m_aim = a_aim;
	m_velocity = a_velocity;

	m_bullet_texture = new aie::Texture("./textures/bullet.png");
	
}

bullet::~bullet()
{
}

void bullet::update(float deltaTime)
{
	b_pos_x += cos(-m_aim - 3.14158f * 0.5f) * m_velocity * deltaTime;
	b_pos_y += -sin(-m_aim - 3.14158f * 0.5f) * m_velocity * deltaTime;
}

void bullet::draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawSprite(m_bullet_texture, b_pos_x, b_pos_y, 20.0f, 20.0f, m_aim, 0, 0.5f, 0.5f);
}






