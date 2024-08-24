#include "Inventory.h"

#include "Player.h" 
#include "Environment.h"

#include "Debug.h"

Inventory::Inventory(Player* owner)
{
	this->owner = owner; 
}

void Inventory::Use()
{
	if (equiped)
		equiped->Use();
}

void Inventory::Pickup(const int objectPoolIndex)  
{
	if (items.size() >= MAX_SIZE)
		return; 

	items.push_back(Environment::s_items[objectPoolIndex]); 
	Environment::s_items[objectPoolIndex]->Pickup(owner);  
	Environment::s_items.erase(Environment::s_items.begin() + objectPoolIndex);

	// double check (look inside the Equip() method). I don't want to equip an item even if one is equiped already
	if (!equiped) 
		Equip(items.size() - 1);  
}

void Inventory::Drop(const int itemIndex) 
{
	if (items.empty() || items.size() - 1 < itemIndex) 
		return;

	if (equiped)
	{
		if (itemIndex < equipedIndex)  
			equipedIndex--;
		else if (equipedIndex == itemIndex)
			Unequip(itemIndex);     
	}

	items[itemIndex]->transform.position = owner->transform.position;  
	items[itemIndex]->rigidbody.velocity = owner->rigidbody.velocity;  
	items[itemIndex]->Drop(); 
	Environment::s_items.push_back(items[itemIndex]); 
	items.erase(items.begin() + itemIndex); 
}

void Inventory::Equip(const int itemIndex)
{
	if (items.size() - 1 < itemIndex || equipedIndex == itemIndex) 
		return;

	if (equiped)
		equiped->Unequip(); 

	items[itemIndex]->Equip();
	equiped = items[itemIndex];
	equipedIndex = itemIndex;
}

void Inventory::Unequip(const int itemIndex) 
{
	if (!equiped || items.size() - 1 < itemIndex || equipedIndex != itemIndex) 
		return;

	equiped->Unequip();
	equiped = nullptr; 
	equipedIndex = -1; 
}

void Inventory::Upgrade(const int itemIndex)
{
}
