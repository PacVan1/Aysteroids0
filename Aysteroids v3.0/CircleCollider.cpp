#include "CircleCollider.h"

#include "Debug.h" 

CircleCollider::CircleCollider(Transform* transformPtr, const float radius, const bool hasPhysics)
{
	this->transformPtr = transformPtr;
	this->radius = radius; 
	this->hasPhysics = hasPhysics; 

	// gizmo
	IDrawable::s_ApplyStyle(gizmo); 
	gizmo.setRadius(radius);
	gizmo.setOrigin(radius, radius);  
	gizmo.setOutlineColor(sf::Color::Green); 
}

vec2 CircleCollider::GetPosition() const 
{
	return transformPtr->position;
}

float CircleCollider::GetRadius() const
{
	return radius; 
}

void CircleCollider::Draw(sf::RenderWindow& window)
{
	if (Debug::drawGizmo)
	{
		gizmo.setPosition(transformPtr->position.x, transformPtr->position.y); 
		window.draw(gizmo);
	}
}

bool CircleCollider::s_CheckCollision(CircleCollider& obj1, CircleCollider& obj2)
{
	vec2 dir =
	{
		obj2.transformPtr->position.x - obj1.transformPtr->position.x,
		obj2.transformPtr->position.y - obj1.transformPtr->position.y 
	};

	float radiiSum = obj1.GetRadius() + obj2.GetRadius();  
	float dist = dir.Mag();

	if (dist < radiiSum)
	{
		if (obj1.hasPhysics && obj2.hasPhysics)
		{
			vec2 displacement = dir * 0.5f / dist * (radiiSum - dist); 
			obj1.transformPtr->position += displacement * -1;   
			obj2.transformPtr->position += displacement;   
		}
		return true;
	}

	return false;
}
