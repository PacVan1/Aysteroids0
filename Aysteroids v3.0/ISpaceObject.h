#pragma once

#include "IUpdatable.h"
#include "IDrawable.h"
#include "Transform.h"
#include "CircleCollider.h"
#include "Rigidbody.h"

struct SpaceObjectProps
{
	float mass; 
	float radius; 
	bool hasFriction;
};

class ISpaceObject : public IUpdatable, public IDrawable
{
public: 
	Transform transform; 
	CircleCollider collider; 
	Rigidbody rigidbody; 

public: 
	void Update(const float& dt) override;
	void Draw(sf::RenderWindow& window) override; 

protected: 
	ISpaceObject(const SpaceObjectProps& spaceObjectProps);  
	ISpaceObject(const float mass, const float radius, const bool hasFriction); 
};

