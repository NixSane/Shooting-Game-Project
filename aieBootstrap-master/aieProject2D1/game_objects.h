#pragma once
#include "Renderer2D.h"
#include "Texture.h"
#include "Input.h"

namespace aie 
{
	class Texture;
	class Renderer2D;
}

class game_objects
{
public:
	game_objects(const char* a_texture);
	
	
	void set_rotation(float a_rot);
	void set_position(float a_x, float a_y);
	void set_radius(float a_radius);
	void set_speed(float a_speed);
	

	float get_rotation() const;
	float get_position_x() const;
	float get_position_y() const;
	float get_radius() const;
	float get_speed() const;
	
	void draw(aie::Renderer2D* a_renderer);

protected:

	float m_rotation;
	float m_position_x;
	float m_position_y;
	float m_radius;
	float m_distance;

	aie::Texture* m_texture; 
};

