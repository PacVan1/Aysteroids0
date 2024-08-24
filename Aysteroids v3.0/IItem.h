#pragma once

#include "CircleCollider.h"
#include "IDrawable.h"
#include "ISpaceObject.h"
#include "Character.h"

struct ItemProps
{
	//sf::Texture* icon; 
	//sf::IntRect iconRect; 
	std::string name; 
	std::string description; 
	float pickupRadius;
	bool disposable; 
};

class IItem : public ISpaceObject
{
public: 
	CircleCollider pickupCollider; 
	//sf::Texture* icon;
	//sf::IntRect iconRect; 
	sf::RectangleShape shape;
	std::string name; 
	std::string description; 
	bool disposable; 

protected: 
	Character* owner = nullptr;  

public: 
	virtual void Use();
	virtual void Pickup(Character* owner); 
	virtual void Drop(); 
	virtual void Equip() = 0;
	virtual void Unequip() = 0;
	void Draw(sf::RenderWindow& window) override; 

protected: 
	IItem(const ItemProps& itemProps, const SpaceObjectProps& spaceObjectProps);
};

