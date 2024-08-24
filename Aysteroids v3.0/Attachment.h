#pragma once

#include "ISpaceObject.h"
#include "IItem.h"
#include "IUsable.h"

class Attachment : public IUsable
{
public: 
	void Pickup(Character* owner) override; 
	void Drop() override; 
	void Equip() override = 0;
	void Unequip() override = 0; 
	void Use() override = 0;  
	void Update(const float& dt) override;  
	void Draw(sf::RenderWindow& window) override; 

protected: 
	Attachment(); 
};

