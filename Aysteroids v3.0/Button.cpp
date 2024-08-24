#include "Button.h"

#include "UI.h"
#include "Input.h" 
#include "Debug.h" 

#include <cmath>

bool Button::selected = false; 
bool Button::pressedPrevious = false; 
SelectionArrow* Button::arrow = new SelectionArrow(4.0f, 10.0f);    

Button::Button(ButtonProps& props) :
	collider(&position, { props.width, props.height }),
	textbox({ props.width, props.height }, UI::s_fontRegular, 14)
{
	this->selectionOffsetMax = props.selectionOffsetMax; 
	this->offsetSpeed = props.offsetSpeed;

	UI::s_buttons.push_back(this);  
	std::cout << UI::s_buttons.size() << std::endl;  
}   

void Button::Update(const float& dt) 
{
	switch (state) 
	{
	case TO_REGULAR:

		if (UndoOffset(dt))  
			state = REGULAR;

		break; 
	case TO_SELECTED: 

		if (DoOffset(dt)) 
			state = SELECTED; 

		break; 
	}

	if (state == SELECTED || state == TO_SELECTED)
		arrow->Update(dt);  
}

void Button::Draw(sf::RenderWindow& window)
{
	textbox.Draw(window); 
	collider.Draw(window); 

	if (state == SELECTED || state == TO_SELECTED) 
		arrow->Draw(window);  
}

void Button::UpdateCollider()
{
	collider.SetSize({ (textbox.GetPosition().x + textbox.GetSize().x) - position.x, textbox.GetSize().y });
}

void Button::SetPosition(const vec2 position)
{
	this->position = position; 
	textbox.SetPosition({ position.x + selectionOffset, position.y }); 
	UpdateCollider(); 
}

vec2 Button::GetPosition() const 
{
	return position; 
}

bool Button::IsSelected()
{
	// another button is already selected
	if (selected || !collider.PointInBox(Input::s_mousePos)) 
	{
		StateToRegular();
		return false; 
	}

	// nothing was selected before, now there is
	selected = true; 

	if (state == UNACTIVE)
		return false; 

	StateToSelected(); 
	return true;  
}

bool Button::IsReleased()
{
	// if this button isn't selected it can't be pressed either
	if (!IsSelected())
		return false; 

	// is button released
	released = (Input::s_leftPressed == false && pressedPrevious == true);
	pressedPrevious = Input::s_leftPressed; 

	if (!released)  
		return false; 

	return true;
}

void Button::StateToSelected()
{
	if (state == SELECTED || state == TO_SELECTED)  
		return;

	state = TO_SELECTED;
	textbox.ChangeColor(sf::Color::Yellow); 
	arrow->SetPosition({ textbox.GetPosition().x - 10.0f, textbox.GetPosition().y + 10.0f}); 
}

void Button::StateToRegular()
{
	if (state == REGULAR || state == TO_REGULAR)
		return; 

	state = TO_REGULAR;
	textbox.ChangeColor(sf::Color::White); 
}

bool Button::DoOffset(const float& dt) 
{
	selectionOffset += offsetSpeed * dt; 

	if (selectionOffset > selectionOffsetMax)
	{
		selectionOffset = selectionOffsetMax; 
		UpdateTextboxPosition(); 
		return true;  
	} 

	UpdateTextboxPosition(); 

	return false;
}

bool Button::UndoOffset(const float& dt) 
{
	selectionOffset -= offsetSpeed * dt;

	if (selectionOffset < 0.0f) 
	{
		selectionOffset = 0.0f;  
		UpdateTextboxPosition(); 
		return true; 
	}

	UpdateTextboxPosition(); 

	return false;
}

void Button::UpdateTextboxPosition()   
{
	textbox.SetPosition({ position.x + selectionOffset, position.y }); 
	UpdateCollider(); 
}

void Button::SetString(const char* string)
{
	textbox.SetString(string); 
}

vec2 Button::GetSize() const
{
	return textbox.GetSize(); 
}

SelectionArrow::SelectionArrow(float offsetMax, float offsetSpeed)
{
	this->offsetMax = offsetMax;
	this->offsetSpeed = offsetSpeed;

	// testing purposes
	//sf::Texture texture;
	//texture.create(10.0f, 10.0f); 

	//arrow.setTexture(texture);  
	arrow.setSize({ 10.0f, 10.0f });
	arrow.setOrigin(5.0f, 5.0f);       
}

void SelectionArrow::Update(const float& dt)
{
	Move(dt);   
}

void SelectionArrow::Draw(sf::RenderWindow& window) 
{
	window.draw(arrow); 
}

void SelectionArrow::SetPosition(vec2 position)
{
	this->position = position; 
	arrow.setPosition(position.x, position.y);  
}

vec2 SelectionArrow::GetPosition() const 
{
	return position;  
}

void SelectionArrow::Move(const float& dt)
{
	offsetAngle += offsetSpeed * dt;
	if (offsetAngle >= 359.0f)
		offsetAngle = 0.0f; 

	float offset = offsetMax * std::cos(offsetAngle);

	arrow.setPosition(position.x + offset, position.y);  
}

