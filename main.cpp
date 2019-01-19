#include "Game.h"

int main()
{
	Game game;
	game.GetParameters();

	while (game.isRunning()){
		game.EventHandler();
	}
	return 0;
}