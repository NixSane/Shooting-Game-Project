#pragma once


class game_objects
{
public:
	game_objects();
	~game_objects();

	void set_speed(float a_speed);
	void set_rotation(float a_rot);
	void set_position(float a_x, float a_y);
	void set_radius(float a_radius);

	float get_speed() const;
	float get_rotation() const;
	float get_position() const;
	float get_radius() const;

protected:

	float rotation;
	float speed;
	float position_x;
	float position_y;
	float m_radius;
};

