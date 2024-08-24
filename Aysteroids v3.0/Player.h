#pragma once

#include "Character.h"
#include "Inventory.h"

class Player : public Character
{
public: 
	Inventory inventory;

public: 
	Player(); 

	void Update(const float& dt) override; 
};

