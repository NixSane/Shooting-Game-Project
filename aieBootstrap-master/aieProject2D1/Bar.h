#pragma once
#include "Renderer2D.h"

class Bar
{
public:
	Bar(float pos_x, float pos_y, float width, float height);
	~Bar();

	void Draw(aie::Renderer2D* renderer);
	
	void set_value(float value);

private:
	// The bar's position, width, and height
	float m_pos_x;
	float m_pos_y;
	float m_width;
	float m_height;

	// The bar's current and maximum value
	float m_current_value;
	float m_max_value;
};

