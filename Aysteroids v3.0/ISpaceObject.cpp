#include "ISpaceObject.h"

#include "Input.h" 

void ISpaceObject::Update(const float& dt)
{
	rigidbody.Update(dt);
}

void ISpaceObject::Draw(sf::RenderWindow& window)
{
	collider.Draw(window); 
}

ISpaceObject::ISpaceObject(const SpaceObjectProps& spaceObjectProps) :
	collider(&transform, spaceObjectProps.radius, true),
	rigidbody(&transform, spaceObjectProps.hasFriction, spaceObjectProps.mass)
{
}

ISpaceObject::ISpaceObject(const float mass, const float radius, const bool hasFriction) :
	collider(&transform, radius, true), 
	rigidbody(&transform, hasFriction, mass)
{
}
