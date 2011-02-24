#include "ImgHolder.h"
#include <iostream>

ImgHolder* ImgHolder::pInstance = NULL;

ImgHolder::ImgHolder()
{
	background = new Image();
	background->LoadFromFile("./data/sprites/background.png");
	hud = new Image();
	hud->LoadFromFile("./data/sprites/HUD.png");
	buttons = new Image();
	buttons->LoadFromFile("./data/sprites/buttons.png");
	blocks = new Image();
	blocks->LoadFromFile("./data/sprites/Blocks3.png");
	ninja = new Image();
	ninja->LoadFromFile("./data/sprites/ninjanimate2a.png");
	colorCode = new Image();
	colorCode->LoadFromFile("./data/sprites/colorcode.png");
	player = new Image();
	player->LoadFromFile("./data/sprites/ninjanimatea.png");

	//menuBackground = new Image();
	//menuBackground->LoadFromFile("./data/sprites/menu/background.png");
	menuButton = new Image();
	menuButton->LoadFromFile("./data/sprites/menu/button.png");
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

	//delete menuBackground;
	delete menuButton;
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