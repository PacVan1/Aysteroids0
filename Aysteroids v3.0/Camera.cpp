#include "Camera.h"

#include <cmath> 

Camera Camera::main = Camera();

Camera::Camera() 
{
	view.reset(sf::FloatRect(0.0f, 0.0f, 600.0f, 600.0f)); 
	view.setSize(600.0f, 600.0f); 
}

void Camera::Update(const float& dt)
{ 
}

void Camera::Follow(const vec2& target, const float& dt)
{
	vec2 viewPos = { view.getCenter().x, view.getCenter().y }; 
	viewPos += vec2::DeltaLerp(viewPos, target, 1.0f) * dt;       
	view.setCenter(viewPos.x, viewPos.y); 
}

void Camera::Shake()
{
}
