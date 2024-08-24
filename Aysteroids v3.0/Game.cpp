#include "Game.h"

#include "ContextSteering.h"
#include "GameSettings.h"
#include "Environment.h"  
#include "Input.h"  
#include "Random.h"
#include "Debug.h"

#include "Player.h"
#include "Gun.h" 
#include "Button.h" 
#include "Menu.h" 
#include "Camera.h" 
#include "UI.h"

ButtonProps buttonStyle1 = { 100.0f, 20.0f, 20.f, 300.0f }; 
Button button(buttonStyle1); 
Button button1(buttonStyle1); 
Button button2(buttonStyle1); 
Button button3(buttonStyle1); 
Menu menu(buttonStyle1, 6); 
 
sf::View view;  

Game::Game() : 
	window(sf::VideoMode(GameSettings::screenWidth, GameSettings::screenHeight), GameSettings::title, sf::Style::Default)    
{
	GameSettings::screenWidth = window.getSize().x;
	GameSettings::screenHeight = window.getSize().y;

	UI::s_LoadFonts(); 

	Random::s_SetSeed();
	ContextSteering::s_SetDirectionsMap(); 

	Environment::s_enemies.push_back(new Enemy()); 
	Environment::s_enemies.push_back(new Enemy()); 
	Environment::s_enemies.push_back(new Enemy()); 
	Environment::s_enemies.push_back(new Enemy()); 
	Environment::s_enemies.push_back(new Enemy()); 

	Gun* gun = new Gun(); gun->transform.position = { 200.0f, 200.0f };    
	Environment::s_items.push_back(gun); 

	running = true; 
}

void Game::HandleFramerate()
{
	deltaTime = clock.restart().asSeconds(); 
}

void Game::GetInputs()
{
	Input::s_GetInputs(window); 
}

void Game::Update()
{ 
	Environment::PickupItems(); 
	Environment::Update(deltaTime);

	UI::Update(deltaTime); 
}

void Game::Draw()
{
	window.clear(); 

	Camera::main.Follow(Environment::s_player->transform.position, deltaTime);     
	window.setView(Camera::main.view); 
	Environment::Draw(window);   

	window.display(); 
}

bool Game::IsRunning()
{
	return window.isOpen() && running; 
}
