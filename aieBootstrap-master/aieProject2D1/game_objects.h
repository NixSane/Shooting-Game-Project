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
	void set_speed(float a_speed);
	void set_alive(bool state);
	

	float get_rotation() const;
	float get_position_x() const;
	float get_position_y() const;
	float get_radius();
	float get_speed() const;
	bool is_alive() { return m_is_alive; };

	bool is_colliding(game_objects* other);
	void update(float deltaTime);
	void draw(aie::Renderer2D* a_renderer);

protected:

	float m_rotation;
	float m_position_x;
	float m_position_y;
	float m_radius;
	float m_distance;
	float m_pi;
	bool m_is_alive;

	aie::Texture* m_texture; 
};

