#pragma once

#include "Transform.h"
#include "IDrawable.h"

class RectangleCollider : public IDrawable 
{
public: 
	vec2* positionPtr; 
	vec2 size; 

private: 
	sf::RectangleShape gizmo; 

public: 
	RectangleCollider(vec2* positionPtr, const vec2 size); 

	void Draw(sf::RenderWindow& window) override; 
	void SetSize(const vec2 size);
	vec2 GetSize() const; 
	bool PointInBox(const vec2& point);

private: 
	bool PointInBoxHorizontal(const vec2& point);
	bool PointInBoxVertical(const vec2& point);
};

