#pragma once

#include "SFML\Graphics.hpp"

class Game
{
public:
	sf::RenderWindow window;
	sf::Clock clock; 
	float deltaTime = 0.0f;  
	bool running; 

public: 
	Game();

	void HandleFramerate();
	void GetInputs(); 
	void Update(); 
	void Draw(); 
	bool IsRunning();
};

