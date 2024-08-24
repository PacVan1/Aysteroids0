#pragma once

#include "ISpaceObject.h"
#include "IVulnerable.h"

class Character : public ISpaceObject, public IVulnerable
{
public: 
	sf::RectangleShape shape;  

protected: 
	float speed; 

public: 
	void Draw(sf::RenderWindow& window) override;

protected: 
	Character(); 

};

