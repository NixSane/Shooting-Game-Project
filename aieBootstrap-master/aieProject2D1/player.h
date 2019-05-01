#pragma once

class player 
{
public:
	player();
	player(float a_speed, int a_lives);
	~player();


	void set_speed(float a_speed);

	float get_speed() const;

	void set_lives(int a_lives);

	int get_lives() const;

private:
	float m_speed = 0.0f;
	int m_lives = 5;
};

