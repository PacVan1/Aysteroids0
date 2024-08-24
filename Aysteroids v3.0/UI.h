#pragma once

#include "IDrawable.h" 
#include "IUpdatable.h" 
#include "RectangleCollider.h"
#include "Camera.h" 
#include "Button.h"

class UI : public IUpdatable, public IDrawable
{
public:  
	static sf::Font s_fontRegular; 
	static sf::Font s_fontBold; 

	static std::vector<Button*> s_buttons;

private: 
	static Camera s_camera;  

public: 
	static void Update(const float& dt); 
	static void Draw(sf::RenderWindow& window); 

	static void s_LoadFonts();

};



