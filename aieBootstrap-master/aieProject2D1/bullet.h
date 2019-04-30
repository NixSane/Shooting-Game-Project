#pragma once
#include "game_objects.h"

class bullet
{
public:
	bullet();
	bullet(bool a_shoot, float a_delay, float delay, float a_cooldown);
	~bullet();

	
	
	void set_delay(float a_delay);
	void set_cooldown(float a_cooldown);
	void set_shooting(bool a_shooting);

	float get_cooldown() const;
	float get_delay() const;
	bool get_shooting() const;

protected:

	bool is_shooting;
	float m_cooldown;
	float m_delay;
};

