#pragma once

#include "Transform.h" 
#include "IUpdatable.h"
#include "IDrawable.h"
#include "RectangleCollider.h" 
#include "Textbox.h"

#include <vector>

class SelectionArrow : public IUpdatable, public IDrawable 
{
private: 
	vec2 position = {}; 

	sf::RectangleShape arrow;  

 	float offsetMax; 
	float offsetAngle = 0.0f;   
	float offsetSpeed; 

public: 
	SelectionArrow(float offsetMax, float offsetSpeed);
	
	void Update(const float& dt) override;
	void Draw(sf::RenderWindow& window) override; 
	void SetPosition(vec2 position);
	vec2 GetPosition() const; 

private: 
	void Move(const float& dt); 
};

struct ButtonProps
{
	float width, height; 
	float selectionOffsetMax;   
	float offsetSpeed; 
};

class Button : public IUpdatable, public IDrawable
{
public: 
	enum states { REGULAR, SELECTED, UNACTIVE, TO_REGULAR, TO_SELECTED }; 
	states state = REGULAR; 

	bool released = false;   

private: 
	vec2 position; 
	Textbox textbox; 
	RectangleCollider collider; 

	float selectionOffset = 0.0f;    
	float selectionOffsetMax; 
	float offsetSpeed;   

public: 
	static SelectionArrow* arrow;   
	static bool selected;
	static bool pressedPrevious;    

public: 
	Button(ButtonProps& props);    

	void Update(const float& dt) override; 
	void Draw(sf::RenderWindow& window) override; 
	void SetPosition(const vec2 position);
	vec2 GetPosition() const;
	vec2 GetSize() const; 
	void SetString(const char* string);

	bool IsSelected();
	bool IsReleased(); 

private: 
	void StateToSelected();
	void StateToRegular();
	bool DoOffset(const float& dt);
	bool UndoOffset(const float& dt);   
	void UpdateCollider();
	void UpdateTextboxPosition(); 

public: 
	void s_InitArrow();

};

class IconedButton 
{
};


