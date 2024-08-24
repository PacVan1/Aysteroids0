#include "Attachment.h"

#include "Debug.h"

void Attachment::Pickup(Character* owner)
{
	IItem::Pickup(owner);  

	shape.setOutlineColor(owner->shape.getOutlineColor());   
}

void Attachment::Drop()
{
	IItem::Drop(); 

	shape.setOutlineColor(sf::Color::White); 
}

void Attachment::Update(const float& dt)
{
	if (owner == nullptr)
	{
		IItem::Update(dt);
		return;
	}

	// stick to the owner
	transform.position = owner->transform.position;     
	transform.angle = owner->transform.angle; 
}
 
void Attachment::Draw(sf::RenderWindow& window) 
{
	shape.setRotation(transform.angle); 

	IItem::Draw(window); 
}

Attachment::Attachment() :
	IUsable(ItemProps({ "gun", "it's a gun", 20.0f, false }), SpaceObjectProps({ 10.0f, 5.0f, true }))
{
}
