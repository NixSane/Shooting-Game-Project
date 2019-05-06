#pragma once
#include "Renderer2D.h"
#include "Font.h"
#include <string>
#include "Input.h"


class button
{
public:
	button(const char* button_text, float x, float y, float width, float height);
	~button();

	void Draw(aie::Renderer2D* renderer);
	bool Update();

private:

	//  Font and text for the button
	aie::Font* m_font;
	char m_button_text[64];
	
	// Button's position, width, and height.
	float m_pos_x;
	float m_pos_y;
	float m_width;
	float m_height;
};

