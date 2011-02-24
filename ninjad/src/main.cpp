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
	int menuChoice = 0;
	
	//menu->splash();

	while(running)
	{
		menuChoice = menu->levelSelect();
		if(menuChoice == -1)
		{
			running = false;
		}
		else
		{
			menu->Show(false);			
			newGame = new Game();
			newGame->init(menuChoice);
			newGame->run();
			delete newGame;
		}
	}

	if(menu)
		delete menu;
	
	delete ImgHolder::getInst();
    return EXIT_SUCCESS;
}