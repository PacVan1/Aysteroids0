#include "Game.h"

int main()
{
	Game game; 

	while (game.IsRunning())
	{
		game.HandleFramerate();
		game.GetInputs(); 
		game.Update(); 
		game.Draw(); 
	}
}