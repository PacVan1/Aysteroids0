#include "AsteroidSpawner.h"

#include "Random.h"
#include "Environment.h"
#include "Random.h" 
#include "GameSettings.h" 

std::vector<AsteroidProps> AsteroidSpawner::asteroidVariants = std::vector<AsteroidProps>(); 

void AsteroidSpawner::s_SpawnWave(const int amount) 
{
	for (int i = 0; i < amount; i++)
	{
		AsteroidProps& asteroidProps = asteroidVariants[Random::s_Int(0, asteroidVariants.size() - 1)]; 
		vec2 position, velocity; s_Launch(position, velocity); 

		s_SpawnSingle(asteroidProps, position, velocity);  
	}
}

void AsteroidSpawner::s_SpawnSingle(AsteroidProps& asteroidProps, const vec2 position, const vec2 velocity)
{
	float radius = Random::s_Float(asteroidProps.radiusMin, asteroidProps.radiusMax); 
	Asteroid* asteroid = new Asteroid(asteroidProps.density, asteroidProps.density * radius, radius, asteroidProps.color);  
	Environment::s_asteroids.push_back(asteroid);  

	asteroid->transform.position = position; 
	asteroid->rigidbody.velocity = velocity;  
}

void AsteroidSpawner::s_SetAsteroidVariants()
{
	// setting up the asteroid variants    dens. | radmin. | radmax. | color 
	AsteroidProps green  = AsteroidProps({ 0.2f,   7.0f,     17.0f,    sf::Color::Green   });  
	AsteroidProps yellow = AsteroidProps({ 0.45f,  8.0f,     24.0f,    sf::Color::Yellow  });   
	AsteroidProps blue   = AsteroidProps({ 0.9f,   4.0f,     14.0f,    sf::Color::Blue    });   
	AsteroidProps red    = AsteroidProps({ 0.6f,   20.0f,    40.0f,    sf::Color::Red     }); 
	AsteroidProps purple = AsteroidProps({ 1.0f,   16.0f,    36.0f,    sf::Color::Magenta });   

	asteroidVariants.push_back(green); 
	asteroidVariants.push_back(yellow); 
	asteroidVariants.push_back(blue); 
	asteroidVariants.push_back(red); 
	asteroidVariants.push_back(purple);  
}

void AsteroidSpawner::s_Launch(vec2& position, vec2& velocity) 
{
	//int side = Random::s_Int(0, 4); 

	//switch (side)
	//{
	//case 0: // Left
	//	position = {};
	//	asteroid->transform.SetPosition({ GameSettings::screenWidth + asteroid->GetRadius(), GetRandomScreenHeight() });
	//	asteroid->rigidbody.SetVelocity({ 0.0f, GetRandomScreenHeight() });
	//	break;
	//case 1: // Up
	//	asteroid->transform.SetPosition({ GetRandomScreenWidth(), GameSettings::screenHeight + asteroid->GetRadius() });
	//	asteroid->rigidbody.SetVelocity({ GetRandomScreenWidth(), 0.0f });
	//	break;
	//case 2: // Right
	//	asteroid->transform.SetPosition({ -asteroid->GetRadius(), GetRandomScreenHeight() });
	//	asteroid->rigidbody.SetVelocity({ (float)GameSettings::screenWidth, GetRandomScreenHeight() });
	//	break;
	//case 3: // Down 
	//	asteroid->transform.SetPosition({ GetRandomScreenWidth(), -asteroid->GetRadius() });
	//	asteroid->rigidbody.SetVelocity({ GetRandomScreenWidth(), (float)GameSettings::screenWidth });
	//	break;
	//}
}
