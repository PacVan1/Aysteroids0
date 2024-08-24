#pragma once

#include "SFML\Graphics.hpp"
#include "Vector2.h"

class Input
{
public: 
	static bool s_leftPressed;   
	static bool s_tab; 
	static bool s_grab; 
	static vec2 s_movement; 
	static vec2 s_mousePos;
	static vec2 s_mousePosWorld; 

public: 
	static void s_GetInputs(sf::RenderWindow& window);  
};

