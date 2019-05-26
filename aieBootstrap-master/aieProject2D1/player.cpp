#include "player.h"



player::player() : game_objects("./textures/ship_2 - Copy.png")
{
	m_speed = 300.0f;
	pi = 3.14158f;

	m_radius = 80.0f;
	m_cooldown = 0.0f;
	m_health = 100.0f;
}


player::~player()
{
}

float player::damage(float atk)
{
	m_health -= atk;

	if (m_health < 1)
	{
		m_health = 0;
	}

	return m_health;
}

void player::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	// Direction inputs
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		m_distance = m_speed;
	}
	else
	{
		m_distance = 0;
	}
	
	
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_rotation += pi * deltaTime;
	}
	
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_rotation += -pi * deltaTime;
	}
	

	m_is_shooting = false;
	m_cooldown += deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && m_cooldown > 0.3f)
	{
		m_is_shooting = true;
		m_cooldown = 0;
	}

	game_objects::update(deltaTime);
}

void player::draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawSprite(m_texture, m_position_x, m_position_y, 0, 0, m_rotation, 0, 0.5f, 0.5f);
}
