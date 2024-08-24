#include "IItem.h"

#include "Debug.h"

void IItem::Use() 
{
}

void IItem::Pickup(Character* owner)
{
	if (owner)
		this->owner = owner; 
}

void IItem::Drop()
{
	owner = nullptr;
}

void IItem::Draw(sf::RenderWindow& window)
{
	pickupCollider.Draw(window);   

	shape.setPosition(transform.position.x, transform.position.y); 
	window.draw(shape); 
}

IItem::IItem(const ItemProps& itemProps, const SpaceObjectProps& spaceObjectProps) :
	ISpaceObject(spaceObjectProps), 
	pickupCollider(&transform, itemProps.pickupRadius, false)  
{
	//icon = itemProps.icon; 
	//iconRect = itemProps.iconRect;  
	name = itemProps.name; 
	description = itemProps.description;
	disposable = itemProps.disposable; 

	IDrawable::s_ApplyStyle(shape); 
	shape.setSize({ spaceObjectProps.radius * 2, spaceObjectProps.radius * 2 }); 
	shape.setOrigin(spaceObjectProps.radius, spaceObjectProps.radius); 
}
