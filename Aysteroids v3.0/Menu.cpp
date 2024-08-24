#include "Menu.h"

Menu::Menu(ButtonProps& props, const int menuSize) :
	buttons(menuSize, Button(props)) 
{
	SetPosition({});
}

void Menu::Draw(sf::RenderWindow& window)
{
	for (Button button : buttons) 
		button.Draw(window);
}
		
void Menu::SetPosition(vec2 position)
{
	buttons[0].SetPosition(position); 

	for (int i = 1; i < buttons.size(); i++)
		buttons[i].SetPosition({ position.x, position.y + ((buttons[i - 1].GetSize().y + buttonSpace) * i) }); 
}

