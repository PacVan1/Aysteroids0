#include "Transform.h"

void Transform::SetRotation(const vec2 rotation)
{
	this->rotation = rotation.Normalized();  
	angle = rotation.Heading(); 
}

vec2 Transform::GetRotation() const
{
	return rotation; 
}

float Transform::GetAngle() const
{
	return angle; 
}
