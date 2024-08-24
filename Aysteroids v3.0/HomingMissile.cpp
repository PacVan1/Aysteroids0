#include "HomingMissile.h"

#include "Environment.h" 

HomingMissile::HomingMissile(const ProjectileProps& projectileProps, const vec2 position, const vec2 velocity, const sf::Color& color) : 
	Projectile(projectileProps, position, velocity, color) 
{
	FindTarget(); 
}

void HomingMissile::FindTarget()
{
	float record = 10000.0f; 

	for (Asteroid* asteroid : Environment::s_asteroids)
	{
		float dist = 0.0f;
		if (transform.position.Dist(asteroid->transform.position) < record)
		{
			record = dist; 
			target = &asteroid->transform.position; 
		}
	}
	 
	for (Enemy* enemy : Environment::s_enemies) 
	{
		float dist = 0.0f; 
		if (transform.position.Dist(enemy->transform.position) < record) 
		{ 
			record = dist; 
			target = &enemy->transform.position;  
		}
	}	
}

void HomingMissile::Update(const float& dt)
{
	if (target)
		rigidbody.Accelarate(vec2::Sub(*target, transform.position).Normalized() * 0.5f);   

	Projectile::Update(dt);
}
