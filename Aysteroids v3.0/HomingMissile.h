#pragma once

#include "Projectile.h" 

class HomingMissile : public Projectile
{
private: 
	vec2* target;  

public: 
	HomingMissile(const ProjectileProps& projectileProps, const vec2 position, const vec2 velocity, const sf::Color& color);

	void FindTarget();
	void Update(const float& dt) override; 
};

