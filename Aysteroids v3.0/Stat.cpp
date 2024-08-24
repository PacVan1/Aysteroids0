#include "Stat.h"

Stat::Stat(const float max)
{
	this->max = max; 
	this->current = max; 
}

void Stat::Increase(const float increment)
{
	current += increment; 

	if (current > max)
		current = max; 
}

void Stat::Decrease(const float decrement)
{
	current -= decrement; 

	if (current < 0.0f) 
		current = 0.0f;
}
