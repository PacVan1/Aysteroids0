#include "UI.h"

#include "Input.h"
#include "Debug.h"

sf::Font UI::s_fontRegular = sf::Font(); 
sf::Font UI::s_fontBold = sf::Font();
std::vector<Button*> UI::s_buttons = std::vector<Button*>(); 

Camera UI::s_camera = Camera();  

void UI::Update(const float& dt)
{
	for (Button* button : s_buttons)
	{
		button->released = false; 
		button->IsReleased();
		button->Update(dt);  
	}

	Button::selected = false;
}

void UI::Draw(sf::RenderWindow& window)
{
	window.setView(s_camera.view);    

	for (Button* button : s_buttons)
		button->Draw(window);
}

void UI::s_LoadFonts()
{
	if (!s_fontRegular.loadFromFile("GravityRegular5.ttf") || 
		!s_fontBold.loadFromFile("GravityBold8.ttf")) 
		Debug::s_ErrorLog("Failed to load font from file");
}
