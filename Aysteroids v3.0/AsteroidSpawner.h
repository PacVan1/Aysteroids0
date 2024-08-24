#pragma once

#include "Asteroid.h"

class AsteroidSpawner
{
private: 
	static std::vector<AsteroidProps> asteroidVariants; 

private: 
	static void s_SetAsteroidVariants(); 
	static void s_Launch(vec2& position, vec2& velocity);  

public: 
	static void s_SpawnWave(const int amount); 
	static void s_SpawnSingle(AsteroidProps& asteroidProps, const vec2 position, const vec2 velocity); 
};

