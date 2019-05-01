#pragma once

namespace aie 
{
	class Texture;
	class Renderer2D;
}

class game_objects
{
public:
	game_objects(aie::Texture* const a_texture);
	
	
	void set_rotation(float a_rot);
	void set_position(float a_x, float a_y);
	void set_radius(float a_radius);
	

	float get_rotation() const;
	float get_position_x() const;
	float get_position_y() const;
	float get_radius() const;
	

	void draw(aie::Renderer2D* a_renderer);

private:

	float m_rotation = 0.0f;
	float m_position_x = 0.0f;
	float m_position_y = 0.0f;
	float m_radius = 0.0f;

	aie::Texture* m_texture = nullptr;
};

