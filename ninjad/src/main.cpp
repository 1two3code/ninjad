#include <iostream>
#include "Menu.h"
#include "Game.h"
#include "ImgHolder.h"

int main()
{
	Menu* menu;
	menu = new Menu();

    Game* newGame;
	newGame = new Game();

	ImgHolder::getInst();

	bool running = true;
	bool quit = false;
	int menuChoice = 0;
	
	menu->splashScreen();

	while(running)
	{
		menuChoice = menu->levelSelect();
		quit = false;
		if(menuChoice == -1)
		{
			running = false;
		}
		else
		{
			while(!quit)
			{
				menu->Show(false);			
				newGame = new Game();
				newGame->init(menuChoice);
				quit = newGame->run();
				delete newGame;
			}
		}
	}

	if(menu)
		delete menu;
	
	delete ImgHolder::getInst();
    return EXIT_SUCCESS;
}