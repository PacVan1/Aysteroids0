#pragma once

#include "Vector2.h"

class Transform
{
public: 
	vec2 position = {};
	float angle = 0.0f;  

private: 
	vec2 rotation = {};

public: 
	void SetRotation(const vec2 rotation);  
	vec2 GetRotation() const;
	float GetAngle() const;
};

