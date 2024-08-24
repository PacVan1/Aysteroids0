#pragma once

#include "Character.h"
#include "ContextSteering.h"
#include "Gun.h" 

class Enemy : public Character
{
private: 
	enum states { FLEE, FOLLOW, ATTACK, FIND_GUN }; 
	states state = FOLLOW;  

	ISpaceObject* target = nullptr; 
	Gun* gun = nullptr;		  
	float playerDetectionRadius = 0.0f, detectionRadius = 0.0f;
	float minAttackRadius = 50.0f, maxAttackRadius = 120.0f; 

	ContextSteering contextSteering; 

public: 
	Enemy(); 

	void Update(const float& dt) override; 
	void Draw(sf::RenderWindow& window) override;  

private: 
	void FindTarget(); 
	void FindGun();
};

