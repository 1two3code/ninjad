#include <iostream>
#include "Game.h"
#include "ImgHolder.h"

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

	delete newGame;
	delete ImgHolder::getInst();
    return EXIT_SUCCESS;
}
