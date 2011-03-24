#include <Windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include "Menu.h"
#include "Game.h"
#include "ImgHolder.h"
#include "SndHolder.h"

unsigned short readConfig();
void writeConfig(unsigned short val);

void sf::Font::SetSmooth(bool smooth){
	this->myTexture.SetSmooth(smooth);
}
using namespace std;

int main()
{
	FreeConsole();			//<- kommentera bort för att få ut consolen
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	unsigned short unlockedLevels = readConfig();
	Menu* menu;
	menu = new Menu();
	menu->setUnlockedLevels(unlockedLevels);

    Game* newGame;
	newGame = new Game();

	ImgHolder::getInst();		//Bara för att initera ImgHolder
	SndHolder::getInst();

	bool running = true;
	int quit = -2;
	int menuChoice = 0;
	
	menu->splashScreen();

	while(running)
	{
		menuChoice = menu->levelSelect();
		quit = -2;
		if(menuChoice == -1)
		{
			running = false;
		}
		else
		{
			while(quit == -2)
			{
				menu->Show(false);			
				newGame = new Game();
				newGame->init(menuChoice);
				quit = newGame->run();
				delete newGame;
				if(quit == -3)
				{
					menuChoice++;
					if(menuChoice >= unlockedLevels)
					{
						menu->setUnlockedLevels(unlockedLevels+1);
						unlockedLevels++;
					}
					quit = -2;
				}
			}
		}
	}

	//Hämta unlocked level värdet från Game och skriv det till fil
	writeConfig(unlockedLevels);

	if(menu)
		delete menu;
	
	delete ImgHolder::getInst();
	delete SndHolder::getInst();
    return EXIT_SUCCESS;
}

unsigned short readConfig()
{
	ifstream istream;
	char lvl[3];
	istream.open("./data/misc/config.cfg");
	istream.getline(lvl, 3);
	istream.close();
	return atoi(lvl);
}

void writeConfig(unsigned short val)
{
	ofstream ostream;
	char lvl[3];
	itoa(val, lvl, 10);
	ostream.open("./data/misc/config.cfg");
	ostream.write(lvl, 3);
	ostream.close();
}