#pragma once

#include "ISpaceObject.h"
#include "IVulnerable.h"
#include "IDrawable.h"

struct AsteroidProps
{
	float density; 
	float radiusMin, radiusMax; 
	sf::Color color; 
};

class Asteroid : public ISpaceObject, IVulnerable
{
public: 
	int minerals;
	float xp; 

private: 
	sf::CircleShape shape; 

public: 
	Asteroid(const float density, const float mass, const float radius, const sf::Color color);  

	Asteroid& Spawn(); 
	void Draw(sf::RenderWindow& window) override; 
};

