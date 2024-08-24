#pragma once

#include "IUpdatable.h"
#include "Transform.h"

class Rigidbody : IUpdatable
{
public: 
	vec2 velocity = {}; 
	const float FRICTION = 0.99f;  

private: 
	Transform* transformPtr;
	vec2 accelaration = {};
	float mass; 
	bool hasFriction;

public: 
	Rigidbody(Transform* transformPtr, const bool hasFriction, const float mass); 

	void Update(const float& dt) override; 
	void Accelarate(const vec2 accelaration);
	void SetAccelaration(const vec2 accelaration);
	float GetMass() const;

public: 
	static void s_CollisionResponse(Rigidbody& obj1, Rigidbody& obj2);  
};

