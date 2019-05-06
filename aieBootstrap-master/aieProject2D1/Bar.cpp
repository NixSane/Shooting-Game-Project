#include "Bar.h"



Bar::Bar(float pos_x, float pos_y, float width, float height) :
	m_pos_x(pos_x), m_pos_y(pos_y), m_width(width), m_height(height)
{
	m_current_value = 100;
	m_max_value = 100;
}


Bar::~Bar()
{
}

void Bar::Draw(aie::Renderer2D* renderer)
{
	// Draw background
	renderer->setRenderColour(1, 0, 0, 1);
	renderer->drawBox(m_pos_x, m_pos_y, m_width, m_height);

	float ratio = m_current_value / m_max_value;
	float full = m_width * ratio;
	float offset_x = m_pos_x - (m_width - full) * 0.5f;

	renderer->setRenderColour(0, 1, 0, 1);
	renderer->drawBox(offset_x, m_pos_y, full, m_height);
	renderer->setRenderColour(1, 1, 1, 1);
}

void Bar::set_value(float value)
{
	m_current_value = value;
}