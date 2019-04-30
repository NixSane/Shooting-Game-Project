#pragma once
class Position
{
	float x, y;
};

class game_objects
{
public:
	game_objects();
	~game_objects();

	void set_speed(float a_speed);

	void set_rotation(float a_rot);


protected:

	float rotation;
	float speed;
	Position position;
};

