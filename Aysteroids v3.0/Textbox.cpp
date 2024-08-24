#include "Textbox.h"

Textbox::Textbox(const vec2 size, const sf::Font& font, int characterSize) 
{
	IDrawable::s_ApplyStyle(border); 
	border.setSize({ size.x, size.y }); 
	this->size = size; 

	text.setFont(font); 
	text.setCharacterSize(characterSize);
}

void Textbox::Draw(sf::RenderWindow& window)
{
	window.draw(border);
	window.draw(text); 
}

void Textbox::SetPosition(const vec2 position)
{
	this->position = position; 

	// flooring the positions to prevent any anti-aliasing effects on the text
	text.setPosition(std::floor(position.x + textOffset), std::floor(position.y + textOffset));
	border.setPosition(position.x, position.y);  
}

vec2 Textbox::GetPosition() const
{
	return position; 
}

vec2 Textbox::GetSize() const 
{
	return size;  
}

void Textbox::SetString(const char* string)
{
	text.setString(string);
	SyncLeftCenter();
}

void Textbox::ChangeColor(const sf::Color& color)
{
	border.setOutlineColor(color); 
	text.setFillColor(color);
}

void Textbox::SyncLeftCenter()
{
	vec2 textBounds = { text.getLocalBounds().width, text.getLocalBounds().height };  

	textOffset = (size.y - textBounds.y) * 0.5f; 
	text.setPosition(std::floor(position.x + textOffset), std::floor(position.y + textOffset));
}
