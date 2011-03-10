#include "ImgHolder.h"
#include <iostream>

ImgHolder* ImgHolder::pInstance = NULL;

ImgHolder::ImgHolder()
{
	background = new Image();
	background->LoadFromFile("./data/sprites/game/background.png");
	background->SetSmooth(false);

	hud = new Image();
	hud->LoadFromFile("./data/sprites/hud/HUD.png");
	hud->SetSmooth(false);

	buttons = new Image();
	buttons->LoadFromFile("./data/sprites/hud/buttons.png");
	buttons->SetSmooth(false);

	arrows = new Image();
	arrows->LoadFromFile("./data/sprites/hud/arrows.png");
	arrows->SetSmooth(false);

	blocks = new Image();
	blocks->LoadFromFile("./data/sprites/game/Blocks.png");
	blocks->SetSmooth(false);

	ninja = new Image();
	ninja->LoadFromFile("./data/sprites/game/ninja.png");
	ninja->SetSmooth(false);

	colorCode = new Image();
	colorCode->LoadFromFile("./data/sprites/game/colorcode.png");

	player = new Image();
	player->LoadFromFile("./data/sprites/game/player.png");
	player->SetSmooth(false);

	hand = new Image();
	hand->LoadFromFile("./data/sprites/game/hand.png");

	pauseScreen = new Image();
	pauseScreen->LoadFromFile("./data/sprites/game//pauseScreen.png");
	pauseScreen->SetSmooth(false);

	icon = new Image();
	icon->LoadFromFile("./data/misc/icon.png");

	splashScreen = new Image();
	splashScreen->LoadFromFile("./data/sprites/menu/Splashscreen.png");

	menuButton = new Image();
	menuButton->LoadFromFile("./data/sprites/menu/button.png");
	menuButton->SetSmooth(false);

	menuNumbers = new Image();
	menuNumbers->LoadFromFile("./data/sprites/menu/numbers.png");
	menuNumbers->SetSmooth(false);

	howToPlay = new Image();
	howToPlay->LoadFromFile("./data/sprites/menu/howtoplay.png");
	howToPlay->SetSmooth(false);

	locked = new Image();
	locked->LoadFromFile("./data/sprites/menu/locked.png");
	locked->SetSmooth(false);

	nMaps = 25;
	maps = new Image*[nMaps];
	char dst[3];
	for(int i = 0; i < nMaps; i++)
	{
		itoa(i, dst, 10);
		std::string fname = "./data/maps/map";
		fname += dst;
		fname += ".png";
		maps[i] = new Image();
		maps[i]->LoadFromFile(fname);
				
		maps[i]->SetSmooth(false);
	}
	
}

ImgHolder::~ImgHolder()
{
	delete background;
	delete hud;
	delete buttons;
	delete blocks;
	delete ninja;
	delete colorCode;
	delete player;
	delete hand;
	delete pauseScreen;
	delete icon;
	delete howToPlay;

	//delete menuBackground;
	delete splashScreen;
	delete menuButton;
	delete menuNumbers;
	delete locked;

	for(int i = 0; i < nMaps; i++)
		delete maps[i];
	
	delete maps;
}

ImgHolder* ImgHolder::getInst()
{
	if(pInstance == NULL)
		pInstance = new ImgHolder();

	return pInstance;
}

Image* ImgHolder::getMaps(int i)
{
	if(i < 0 || i > nMaps-1)
		return NULL;
	else
		return maps[i];
}