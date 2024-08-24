#pragma once

#include "Asteroid.h"
#include "IItem.h" 
#include "Player.h"
#include "Enemy.h" 
#include "Projectile.h" 
#include <vector>

class Environment
{
public:
	static std::vector<Asteroid*> s_asteroids; 
	static std::vector<IItem*> s_items; 
	static std::vector<Enemy*> s_enemies; 
	static std::vector<Projectile*> s_projectiles; 

	static Player* s_player; 

public: 
	static void Update(const float& dt); 
	static void Draw(sf::RenderWindow& window); 
	static bool CheckBorder(const CircleCollider& obj);
	static void PickupItems(); 
	static void Clear(); 

private:
	static bool CheckHorizontal(const CircleCollider& obj);
	static bool CheckVertical(const CircleCollider& obj); 

//private: 
};

