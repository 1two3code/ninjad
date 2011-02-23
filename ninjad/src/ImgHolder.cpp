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

	nMaps = 10;
	maps = new Image*[nMaps];
	char dst[2];
	for(int i = 0; i < nMaps; i++)
	{
		itoa(i, dst, 10);
		std::string fname = "./data/sprites/maps/map";
		fname += dst;
		//fname += "5";
		fname += ".png";
		maps[i] = new Image();
		maps[i]->LoadFromFile(fname);
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