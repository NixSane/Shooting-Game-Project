#include "player.h"



player::player(const char* a_text, float a_pos_x, float a_pos_y, float a_rot, float a_speed)
{
	m_texture_ship = new aie::Texture(a_text);
	m_position_x = a_pos_x;
	m_position_y = a_pos_y;
	m_rotation = a_rot;
	m_speed = a_speed;
	pi = 3.14158f;
	m_radius = 0.1f;
	m_cooldown = 0.0f;
}


player::~player()
{
}
float player::get_pos() const
{
	return m_position_x, m_position_y;
}

float player::get_pos_x() const
{
	return m_position_x;
}

float player::get_pos_y() const
{
	return m_position_y;
}

float player::get_rot() const
{
	return m_rotation;
}

void player::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	// Direction inputs
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		m_position_x += cos(-m_rotation - pi * 0.5f) * m_speed * deltaTime;
		m_position_y += -sin(-m_rotation - pi * 0.5f) * m_speed * deltaTime;
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

}

void player::draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawSprite(m_texture_ship, m_position_x, m_position_y, 0, 0, m_rotation, 0, 0.5f, 0.5f);
	a_renderer->drawCircle(m_position_x, m_position_y, m_radius, 0);
}

