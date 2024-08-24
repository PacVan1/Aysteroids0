#pragma once

#include "Stat.h" 

class IVulnerable
{
public: 
	Stat health; 
	bool dead = false;   

public: 
	void Decrease(const float decrement);

protected: 
	IVulnerable(const float max); 
};

