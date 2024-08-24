#include "Enemy.h"
	
#include "Environment.h" 
#include "Random.h" 
		
Enemy::Enemy() :  
	contextSteering(&transform, minAttackRadius, 1.2f)  
{   
	gun = new Gun();  
	gun->Pickup(this); 

	transform.position = { (float)Random::s_Float(50.0f, 150.0f), (float)Random::s_Float(50.0f, 150.0f) };  
}   
	
void Enemy::Update(const float& dt)
{
	std::vector<ISpaceObject*> obstacles;

	obstacles.push_back(Environment::s_player); 
	for (Asteroid* asteroid : Environment::s_asteroids)
		obstacles.push_back(asteroid);
	for (Enemy* enemy : Environment::s_enemies)
		obstacles.push_back(enemy); 

	std::vector<float> interestMap(contextSteering.NUMBER_OF_DIRECTIONS);    
	std::vector<float> dangerMap(contextSteering.NUMBER_OF_DIRECTIONS); 

	if (transform.position.Dist(Environment::s_player->transform.position) > maxAttackRadius)
	{
		interestMap = contextSteering.CalculateInterest(*Environment::s_player, false);  
	}
	else
	{
		gun->Use();   
	}

	dangerMap = contextSteering.CalculateDanger(obstacles);

	//// make this a state machine in the future
	//switch (state)
	//{
	//case FLEE: 


	//	break; 
	//case FOLLOW: 
	//	break; 
	//case ATTACK: 
	//	break; 
	//case FIND_GUN:   
	//	break; 
	//}

	vec2 result = contextSteering.CalculateDesire(interestMap, dangerMap); 
	rigidbody.Accelarate(result * speed); 

	transform.SetRotation(Environment::s_player->transform.position - transform.position);  
	Character::Update(dt); 
	gun->Update(dt); 
}

void Enemy::Draw(sf::RenderWindow& window) 
{
	gun->Draw(window);

	Character::Draw(window); 
}

void Enemy::FindTarget() 
{
}

void Enemy::FindGun()
{
}
