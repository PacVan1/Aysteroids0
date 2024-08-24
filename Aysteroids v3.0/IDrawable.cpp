#include "IDrawable.h"

unsigned int IDrawable::s_outlineThickness = 3;

void IDrawable::s_ApplyStyle(sf::Shape& shape)
{
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(s_outlineThickness); 
}
