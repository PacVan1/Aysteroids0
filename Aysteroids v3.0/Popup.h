#pragma once

#include "IDrawable.h"

class Popup : IDrawable
{
private: 
	sf::RectangleShape shape; 

public: 
	Popup();

	void Pop(); 
};

