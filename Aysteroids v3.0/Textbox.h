#pragma once

#include "IDrawable.h"
#include "Transform.h"

class Textbox : IDrawable
{
public: 
	sf::Text text;

private:
	sf::RectangleShape border;

	vec2 position = {}; 
	vec2 size; 

	float textOffset = 0.0f;  

public: 
	Textbox(const vec2 size, const sf::Font& font, int characterSize);   

	void Draw(sf::RenderWindow& window) override;  
	void SetPosition(const vec2 position);
	vec2 GetPosition() const;
	vec2 GetSize() const; 
	void SetString(const char* string); 
	void ChangeColor(const sf::Color& color);

//private:  
	void SyncLeftCenter();
};

