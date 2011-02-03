#include "Level.h"
#include <iostream>
Level::Level(int j)
{
	generateBlocks(j);
	
	//Block blk();
	
}

Level::~Level()
{
	for(int i = 0; i < nBlocks; i++)
	{
		delete block[i];
	}
	delete block;
}

void Level::render(RenderWindow* rnd)
{
	for(int i= 0; i < nBlocks; i++)
		rnd->Draw(*block[i]);
}

void Level::generateBlocks(int j)
{
	Image* map;
	map = ImgHolder::getInst()->getMaps(j);
	if(map == NULL)
		map = ImgHolder::getInst()->maps[0];

	int w = map->GetWidth();
	int h = map->GetHeight();
	int blockType = 0;

	nBlocks = 0;
	maxBlocks = w*h;
	block = new Block*[324];
	Block* tempBlock;

	
	for(int i = 0; i < w; i++)
	{
		for(int j = 0; j < h; j++)
		{
			blockType = findType(map->GetPixel(i, j));
			tempBlock = createBlock(blockType);
			if(tempBlock != NULL)
			{
				block[nBlocks] = tempBlock;
				block[nBlocks]->SetPosition(16+i*32.0f, 16+j*32.0f);
				nBlocks++;
				tempBlock = NULL;

			}			

		}
	}

}

int Level::findType(Color col)
{
	Image* code = ImgHolder::getInst()->colorCode;	

	for(int i = 0; i < (int)code->GetWidth(); i++)
	{
		if(col == code->GetPixel(i, 0))
		{
			return i;
		}
	}

	return 0;
}

Block* Level::createBlock(int type)
{
	Block* rtn;
	
	switch(type)
	{
	case 0:
		rtn = NULL;
		break;
	case 1:
		rtn = new StdBlock();
		break;
	case 2:
		rtn = NULL;
		//Dörrexit
		break;
	case 3:
		rtn = NULL;
		//Dörröppning
		break;
	case 4:
		rtn = NULL;
		break;
	case 5:
		rtn = NULL;
		break;
	case 6:
		rtn = NULL;
		break;
	case 7:
		rtn = NULL;
		break;
	case 8:
		rtn = NULL;
		break;
	case 9:
		rtn = NULL;
		break;
	case 10:
		rtn = NULL;
		break;
	case 11:
		rtn = NULL;
		break;
	default:
		rtn = NULL;
		break;
	}
	return rtn;
}

