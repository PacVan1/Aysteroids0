#pragma once

#include "Button.h" 

class Menu : public IDrawable
{
	// Arrays of data for each actual button
	// A way to select which buttons you want
private:
	std::vector<Button> buttons;
	vec2 position = {};
	int buttonSpace = 10;
	//const int menuSize; 

public:
	Menu(ButtonProps& props, const int menuSize); 

	void Draw(sf::RenderWindow& window) override;
	void SetPosition(vec2 position);

};

