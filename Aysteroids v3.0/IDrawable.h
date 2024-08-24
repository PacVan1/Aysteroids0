#pragma once

#include "SFML\Graphics.hpp"

class IDrawable
{
public: 
	static unsigned int s_outlineThickness;

public: 
	virtual void Draw(sf::RenderWindow& window) = 0; 

public:		
	static void s_ApplyStyle(sf::Shape& shape);  
};

