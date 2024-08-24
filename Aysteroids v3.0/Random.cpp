#include "Random.h"

#include <random> 
#include <ctime>

void Random::s_SetSeed()
{
	srand(static_cast<unsigned int>(time(0)));
}

int Random::s_Int(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int Random::s_Float(float min, float max)
{
	return ((rand() % 101) / 100.0f) * (max - min) + min;
}
