#include "RectangleCollider.h"

#include "Debug.h" 

RectangleCollider::RectangleCollider(vec2* positionPtr, const vec2 size) : 
	positionPtr(positionPtr) 
{
	this->size = size; 

	// gizmo
	gizmo.setOutlineThickness(1);
	gizmo.setFillColor(sf::Color::Transparent);
	gizmo.setSize({ size.x, size.y });
	gizmo.setOutlineColor(sf::Color::Green);
}

void RectangleCollider::Draw(sf::RenderWindow& window)
{
	if (!Debug::drawGizmo)
		return; 
	
	gizmo.setPosition(positionPtr->x, positionPtr->y); 
	window.draw(gizmo); 
}

void RectangleCollider::SetSize(const vec2 size) 
{
	this->size = size; 
	gizmo.setSize({ size.x, size.y }); 
}

vec2 RectangleCollider::GetSize() const
{
	return size;
}

bool RectangleCollider::PointInBox(const vec2& point)
{
	return (PointInBoxHorizontal(point) && PointInBoxVertical(point));
}

bool RectangleCollider::PointInBoxHorizontal(const vec2& point)
{
	return (point.x > positionPtr->x && point.x < positionPtr->x + size.x);
}

bool RectangleCollider::PointInBoxVertical(const vec2& point)
{
	return (point.y > positionPtr->y && point.y < positionPtr->y + size.y);  
}
