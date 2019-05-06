#pragma once
#include "game_objects.h"



class bullet 
{
public:
	bullet();
	~bullet();

	
	
	void set_delay(float a_delay);
	float get_delay() const;



private:

	float m_delay;

};

