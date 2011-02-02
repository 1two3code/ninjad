#include <iostream>
#include "Game.h"

int main()
{
    Game* newGame;
	bool running = true;

	while(running)
	{
		newGame = new Game();
		newGame->init(0);
		running = newGame->run();
	}

    return EXIT_SUCCESS;
}
