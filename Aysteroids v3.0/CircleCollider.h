#pragma once

#include "Transform.h"
#include "IDrawable.h"

class CircleCollider : public IDrawable 
{
private: 
	Transform* transformPtr; 
	float radius; 
	bool hasPhysics; 

	sf::CircleShape gizmo;

public: 
	CircleCollider(Transform* transformPtr, const float radius, const bool hasPhysics);  

	vec2 GetPosition() const;  
	float GetRadius() const;
	void Draw(sf::RenderWindow& window) override; 

public: 
	static bool s_CheckCollision(CircleCollider& obj1, CircleCollider& obj2);
};

