#include "Environment.h"

#include "Input.h"
#include "Debug.h"
#include "GameSettings.h" 

std::vector<Asteroid*> Environment::s_asteroids = std::vector<Asteroid*>(); 
std::vector<IItem*> Environment::s_items = std::vector<IItem*>();
std::vector<Enemy*> Environment::s_enemies = std::vector<Enemy*>();   
std::vector<Projectile*> Environment::s_projectiles = std::vector<Projectile*>();  
Player* Environment::s_player = new Player();    

void Environment::Update(const float& dt)
{
	// collision  
	for (Enemy* enemy : s_enemies) 
		for (Enemy* enemy2 : s_enemies)
			if (enemy != enemy2)  
				if (CircleCollider::s_CheckCollision(enemy->collider, enemy2->collider)) 
					Rigidbody::s_CollisionResponse(enemy->rigidbody, enemy2->rigidbody);              

	for (Enemy* enemy : s_enemies)  
		if (CircleCollider::s_CheckCollision(enemy->collider, s_player->collider))   
			Rigidbody::s_CollisionResponse(enemy->rigidbody, s_player->rigidbody);  

	for (Projectile* projectile : s_projectiles)
	{
		for (Projectile* projectile2 : s_projectiles)
			if (projectile != projectile2)
				if (CircleCollider::s_CheckCollision(projectile->collider, projectile2->collider)) 
					Rigidbody::s_CollisionResponse(projectile->rigidbody, projectile2->rigidbody); 

		for (Enemy* enemy : s_enemies)
			if (CircleCollider::s_CheckCollision(projectile->collider, enemy->collider)) 
				Rigidbody::s_CollisionResponse(projectile->rigidbody, enemy->rigidbody);  
	}

	for (IItem* item : s_items) 
		if (CircleCollider::s_CheckCollision(item->collider, s_player->collider))  
			Rigidbody::s_CollisionResponse(item->rigidbody, s_player->rigidbody);  

	//for (Asteroid* asteroid : s_asteroids)
	//	asteroid->Update(dt); 

	for (IItem* item : s_items) 
		item->Update(dt);

	for (Enemy* enemy : s_enemies)
		enemy->Update(dt);  

	for (Projectile* projectile : s_projectiles) 
		projectile->Update(dt);

	if (!s_player->dead)
	{
		if (s_player->inventory.equiped)
			s_player->inventory.equiped->Update(dt);

		s_player->Update(dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		s_player->inventory.Drop(1);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		s_player->inventory.Equip(0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		s_player->inventory.Equip(1); 

	auto itemOutOfBorder = [](IItem* item) { return CheckBorder(item->collider); };       
	auto projectileOutOfBorder = [](Projectile* projectile) { return CheckBorder(projectile->collider); };    
	auto asteroidOutOfBorder = [](Asteroid* asteroid) { return CheckBorder(asteroid->collider); };   
	s_items.erase(remove_if(s_items.begin(), s_items.end(), itemOutOfBorder), s_items.end());  
	s_projectiles.erase(remove_if(s_projectiles.begin(), s_projectiles.end(), projectileOutOfBorder), s_projectiles.end());   
	//s_asteroids.erase(remove_if(s_asteroids.begin(), s_asteroids.end(), asteroidOutOfBorder), s_asteroids.end());  
}

void Environment::Draw(sf::RenderWindow& window)
{ 
	//for (Asteroid* asteroid : s_asteroids)
	//	asteroid->Draw(window); 

	for (IItem* item : s_items)
		item->Draw(window);  

	for (Enemy* enemy : s_enemies) 
		enemy->Draw(window); 

	for (Projectile* projectile : s_projectiles) 
		projectile->Draw(window); 

	if (!s_player->dead)
	{
		if (s_player->inventory.equiped)
			s_player->inventory.equiped->Draw(window);

		s_player->Draw(window);
	}
}

bool Environment::CheckBorder(const CircleCollider& obj)
{
	return (CheckHorizontal(obj) || CheckVertical(obj)); 
}

bool Environment::CheckHorizontal(const CircleCollider& obj)
{
	return (obj.GetPosition().x + obj.GetRadius() < 0.0f || obj.GetPosition().x - obj.GetRadius() > GameSettings::screenWidth); 
}

bool Environment::CheckVertical(const CircleCollider& obj)
{
	return (obj.GetPosition().y + obj.GetRadius() < 0.0f || obj.GetPosition().y - obj.GetRadius() > GameSettings::screenHeight);   
}

void Environment::PickupItems()
{
	if (!Input::s_grab)
		return; 

	for (int i = 0; i < s_items.size(); i++)
	{
		if (CircleCollider::s_CheckCollision(s_items[i]->pickupCollider, s_player->collider))
			s_player->inventory.Pickup(i); 
	}
}
