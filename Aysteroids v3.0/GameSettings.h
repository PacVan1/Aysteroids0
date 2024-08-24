#pragma once

#include <iostream> 

class GameSettings
{
public:
	static enum gameStates {};
	static gameStates state; 

	static std::string title;
	static unsigned int screenWidth; 
	static unsigned int screenHeight;

};

