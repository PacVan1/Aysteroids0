#include "Player.h"

#include "Input.h"
#include "Debug.h"

Player::Player() : 
	inventory(this)     
{
	shape.setOutlineColor(sf::Color::Green); 
}

void Player::Update(const float& dt)
{
	rigidbody.Accelarate(Input::s_movement * speed);  
	transform.SetRotation(Input::s_mousePosWorld - transform.position); 
	
	if (Input::s_leftPressed && inventory.equiped)
		inventory.equiped->Use(); 

	Character::Update(dt); 
}
