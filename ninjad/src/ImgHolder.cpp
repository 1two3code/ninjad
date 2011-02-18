#include "ImgHolder.h"
#include <iostream>

ImgHolder* ImgHolder::pInstance = NULL;

ImgHolder::ImgHolder()
{
	blocks = new Image();
	blocks->LoadFromFile("./data/sprites/Blocks2.png");
	ninja = new Image();
	ninja->LoadFromFile("./data/sprites/ninjanimate2a.png");
	colorCode = new Image();
	colorCode->LoadFromFile("./data/sprites/colorcode.png");
	player = new Image();
	player->LoadFromFile("./data/sprites/ninjanimatea.png");

	nMaps = 1;
	maps = new Image*[nMaps];
	char dst[2];
	for(int i = 0; i < nMaps; i++)
	{
		itoa(i, dst, 10);
		std::string fname = "./data/sprites/maps/map";
		//fname += dst;
		fname += "4";
		fname += ".png";
		maps[i] = new Image();
		maps[i]->LoadFromFile(fname);
		//std::cout << fname << std::endl;
	}
	
}

ImgHolder::~ImgHolder()
{
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