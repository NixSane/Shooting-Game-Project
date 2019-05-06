#include "button.h"



button::button(const char* button_text, float x, float y, float width, float height)
{
	// Store the text that will appear on the button
	strcpy_s(m_button_text, 64, button_text);

	// Load a font to use to display the text.
	m_font = new aie::Font("./font/consolas.ttf", 24);

	// Store the button's position, width, and height
	m_pos_x = x;
	m_pos_y = y;
	m_width = width;
	m_height = height;
}

button::~button()
{
	delete m_font;
}

void button::Draw(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(0.0f, 0.5f, 0.7f, 1.0f);
	renderer->drawBox(m_pos_x, m_pos_y, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	// Calculating the centred text position
	float text_width = m_font->getStringWidth(m_button_text);
	float text_height = m_font->getStringHeight(m_button_text);
	float centred_pos_x = m_pos_x - (text_width * 0.5f) + 2;
	float centred_pos_y = m_pos_y - (text_height * 0.5) + 5;

	// Draw the text on button
	renderer->drawText(m_font, m_button_text, centred_pos_x, centred_pos_y);
}

bool button::Update()
{
	aie::Input* input = aie::Input::getInstance();

	// Get mouse position
	int mouse_x = input->getMouseX();
	int mouse_y = input->getMouseY();

	// Calculate the  4 sides of the button
	float left = m_pos_x - (m_width * 0.5f);
	float right = m_pos_x + (m_width * 0.5f);
	float bottom = m_pos_y - (m_height * 0.5f);
	float top = m_pos_y + (m_height * 0.5f);

	// Check if the  mouse is inside the box made by the 4 sides.
	if (mouse_x > left && mouse_x < right && mouse_y > bottom && mouse_y < top)
	{
		// Return whether the mouse button is clicked while colliding
		return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}
	return false;
}
