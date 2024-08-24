#pragma once

#include "IItem.h"
#include "IUsable.h" 

class Player;

class Inventory
{
public: 
	IItem* equiped = nullptr; 

private: 
	const int MAX_SIZE = 6;
	std::vector<IItem*> items; 
	Player* owner;  
	int equipedIndex = -1;  

public: 
	Inventory(Player* owner);

	void Use();
	void Pickup(const int objectPoolIndex);  
	void Drop(const int itemIndex); 
	void Equip(const int itemIndex);   
	void Unequip(const int itemIndex); 
	void Upgrade(const int itemIndex); 
};

