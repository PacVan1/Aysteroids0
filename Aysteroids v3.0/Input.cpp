#include "Input.h"

#include "Camera.h"

bool Input::s_leftPressed = false; 
bool Input::s_tab = false; 
bool Input::s_grab = false; 
vec2 Input::s_movement = {}; 
vec2 Input::s_mousePos = {};  
vec2 Input::s_mousePosWorld = {};  

void Input::s_GetInputs(sf::RenderWindow& window) 
{
	window.setView(Camera::main.view);

	s_leftPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left); 
	s_tab = sf::Keyboard::isKeyPressed(sf::Keyboard::Tab); 
	s_grab = sf::Keyboard::isKeyPressed(sf::Keyboard::E); 

	s_movement.x = sf::Keyboard::isKeyPressed(sf::Keyboard::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A);   
	s_movement.y = sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W); 

	s_mousePos.x = sf::Mouse::getPosition(window).x; 
	s_mousePos.y = sf::Mouse::getPosition(window).y; 

	sf::Vector2f worldPos = window.mapPixelToCoords({ (int)s_mousePos.x, (int)s_mousePos.y });
	s_mousePosWorld = { worldPos.x, worldPos.y };
}
