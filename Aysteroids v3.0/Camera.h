#pragma once

#include "SFML\Graphics.hpp" 
#include "IUpdatable.h"
#include "Vector2.h"

class Camera : public IUpdatable 
{
public: 
	sf::View view; 

public: 
	static Camera main;

public: 
	Camera(); 

	void Update(const float& dt) override; 
	void Follow(const vec2& target, const float& dt);  
	void Shake();

};

