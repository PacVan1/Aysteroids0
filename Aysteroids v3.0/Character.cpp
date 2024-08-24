#include "Character.h"

void Character::Draw(sf::RenderWindow& window)
{
	shape.setPosition(transform.position.x, transform.position.y); 
	shape.setRotation(transform.angle); 

	ISpaceObject::Draw(window); 
	window.draw(shape); 
}

Character::Character() :
	ISpaceObject(10.0f, 10.0f, true),
	IVulnerable(10.0f)
{
	speed = 0.2f;

	// temporary replacement for sprites
	IDrawable::s_ApplyStyle(shape);
	shape.setSize({ collider.GetRadius() * 2, collider.GetRadius() * 2 });
	shape.setOrigin(collider.GetRadius(), collider.GetRadius());
}
