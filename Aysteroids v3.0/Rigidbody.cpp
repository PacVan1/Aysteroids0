#include "Rigidbody.h"

Rigidbody::Rigidbody(Transform* transformPtr, const bool hasFriction, const float mass)
{
	this->transformPtr = transformPtr;
	this->hasFriction = hasFriction; 
	this->mass = mass;  
}

void Rigidbody::Update(const float& dt)
{
	velocity += accelaration; 
	accelaration = {};

	transformPtr->position += velocity * dt;   

	if (hasFriction)
		Accelarate(velocity * (-FRICTION * dt)); 
}

void Rigidbody::Accelarate(const vec2 accelaration)
{
	this->accelaration += accelaration;
}

void Rigidbody::SetAccelaration(const vec2 accelaration)
{
	this->accelaration = accelaration; 
}

float Rigidbody::GetMass() const
{
	return mass; 
}

void Rigidbody::s_CollisionResponse(Rigidbody& obj1, Rigidbody& obj2)
{
	// 2-Dimensional Elastic Collisions without Trigonometry by Chad Berchek
	// https://www.vobarian.com/collisions/2dcollisions2.pdf

	vec2 n = obj2.transformPtr->position - obj1.transformPtr->position;  
	vec2 un = n.Normalized();  // unit normal  
	vec2 ut = { -un.y, un.x }; // unit tangent

	// take the dot product of the two vectors and the two axis (tangent and normal)
	float s1n = un.x * obj1.velocity.x + un.y * obj1.velocity.y;  // scalar normal 1 
	float fs1t = ut.x * obj1.velocity.x + ut.y * obj1.velocity.y; // final scalar tangent 1 
	float s2n = un.x * obj2.velocity.x + un.y * obj2.velocity.y;  // scalar normal 2 
	float fs2t = ut.x * obj2.velocity.x + ut.y * obj2.velocity.y; // final scalar tangent 2 

	// conservation of momentum and conversation of kinetic energy formula for one dimensional elastic collision
	float mass1 = obj1.GetMass();
	float mass2 = obj2.GetMass();
	float fs1n = (s1n * (mass1 - mass2) + 2 * mass2 * s2n) / (mass1 + mass2); // final scalar normal 1
	float fs2n = (s2n * (mass2 - mass1) + 2 * mass1 * s1n) / (mass1 + mass2); // final scalar normal 2

	vec2 fv1 = (un * fs1n) + (ut * fs1t); // final vector 1
	vec2 fv2 = (un * fs2n) + (ut * fs2t); // final vector 2

	obj1.velocity = fv1;
	obj2.velocity = fv2;
}
