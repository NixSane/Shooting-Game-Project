#pragma once
#include "game_objects.h"

class bullet 
{
public:
	bullet();
	bullet(bool a_shoot, float a_delay);
	~bullet();

	
	
	void set_delay(float a_delay);
	void set_shooting(bool a_shooting);

	
	float get_delay() const;
	bool get_shooting() const;

protected:

	bool m_is_shooting;

	float m_delay;
};

