#pragma once

#include "ISpaceObject.h" 

struct ProjectileProps
{
	float mass; 
	float radius; 
};

class Projectile : public ISpaceObject
{
public: 
	bool dead = false; 

private: 
	sf::CircleShape shape; 

public: 
	Projectile(const ProjectileProps& projectileProps, const vec2 position, const vec2 velocity, const sf::Color& color); 

	void Draw(sf::RenderWindow& window) override; 
};

