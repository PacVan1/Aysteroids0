#include "Asteroid.h"

#include "Random.h" 
#include <cmath>

Asteroid::Asteroid(const float density, const float mass, const float radius, const sf::Color color) : 
	ISpaceObject(mass, radius, false),    
	IVulnerable(mass)
{
	IDrawable::s_ApplyStyle(shape);
	shape.setRadius(radius);
	shape.setOrigin(radius, radius); 
	shape.setOutlineColor(color); 

	minerals = std::max(1, Random::s_Int(radius - 20, radius + 20));  
	xp = Random::s_Float(density - 0.6f, density + 0.6f); 
}

void Asteroid::Draw(sf::RenderWindow& window)
{
	shape.setPosition(transform.position.x, transform.position.y); 
	window.draw(shape);
}

//Asteroid& Asteroid::Spawn()
//{
//	return Asteroid();
//}
