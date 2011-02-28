#include "Level.h"
#include <iostream>
Level::Level(int j)
{
	nLevel = j;
	nNinjas = 0;
	nNinjas = 0;
	nPBlocks = 0;
	nJBlocks = 0;
	nSBlocks = 0;
	nFBlocks = 0;
	generateBlocks(j);
	
	//Parsa mapfil mapj.cfg
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
	{
		if(block[i]->GetPosition().x > 96 && block[i]->GetPosition().x < 608 && block[i]->GetPosition().y > 160 && block[i]->GetPosition().y < 672)
		//if(block[i]->GetPosition().x > 512)
			rnd->Draw(*block[i]);
	}
}

void Level::generateBlocks(int j)
{
	Image* map;
	map = ImgHolder::getInst()->getMaps(j);
	if(map == NULL)
		map = ImgHolder::getInst()->maps[0];

	int w = map->GetWidth();
	int h = map->GetHeight()-1;
	int blockType = 0;
	int blockRot = 0;

	nBlocks = 0;
	maxBlocks = w*h;
	block = new Block*[324];
	Block* tempBlock;

	
	for(int i = 0; i < w; i++)
	{
		for(int j = 0; j < h; j++)
		{
			blockType = findType(map->GetPixel(i, j));
			blockRot = findRotation(map->GetPixel(i, j), blockType);
			tempBlock = createBlock(blockType, blockRot);
			if(tempBlock != NULL)
			{
				if(blockType == 3)
					entryDoor = tempBlock;
				block[nBlocks] = tempBlock;
				block[nBlocks]->SetPosition(64+16+i*32.0f, 128+16+j*32.0f);
				nBlocks++;
				tempBlock = NULL;

			}
		}
	}


	nNinjas = map->GetPixel(0, 18).r;
	nPBlocks = map->GetPixel(1, 18).r;
	nJBlocks = map->GetPixel(2, 18).r;
	nSBlocks = map->GetPixel(3, 18).r;
	nFBlocks = map->GetPixel(4, 18).r;

}

int Level::findType(Color col)
{
	Image* code = ImgHolder::getInst()->colorCode;	

	for(int i = 0; i < (int)code->GetWidth(); i++)
	{
		if(col.r == code->GetPixel(i, 0).r && col.g == code->GetPixel(i, 0).g && col.b == code->GetPixel(i, 0).b)
		{
			return i;
		}
	}

	return 0;
}

int Level::findRotation(Color col, int type)
{
	Image* code = ImgHolder::getInst()->colorCode;
	int rot = 0;
	for(int i = 0; i < 4; i++)
	{
		if(col == code->GetPixel(type, i))
			return rot;
		else
			rot += 90;
	}
	return rot;
}

Block* Level::createBlock(int type, int rot)
{
	Block* rtn;
	
	switch(type)
	{
	case 0:
		rtn = NULL;
		break;
	case 1:
		rtn = new StdBlock();
		rtn->SetRotation(rot);
		break;
	case 2:
		rtn = new ExitDoor();
		rtn->SetRotation(rot);
		break;
	case 3:
		rtn = new EntryDoor();
		rtn->SetRotation(rot);
		break;
	case 4:
		rtn = new SpringBlock();
		rtn->SetRotation(rot);
		break;
	case 5:
		rtn = new JumpBlock();
		rtn->SetRotation(rot);
		break;
	case 6:
		rtn = new FallBlock();
		rtn->SetRotation(rot);
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

int Level::getNr()
{
	return nBlocks;
}

Block** Level::getBlocks()
{
	return this->block;
}

Block* Level::getEntryDoor()
{
	return entryDoor;
}

unsigned short Level::getNLevel()
{
	return nLevel;
}
unsigned short Level::getNNinjas()
{
	return nNinjas;
}
unsigned short Level::getNPBlocks()
{
	return nPBlocks;
}
unsigned short Level::getNJBlocks()
{
	return nJBlocks;
}
unsigned short Level::getNSBlocks()
{
	return nSBlocks;
}
unsigned short Level::getNFBlocks()
{
	return nFBlocks;
}

int Level::addBlock(int type, int posX, int posY, int rot) //type används inte än
{

	Block* tempBlock;
	int x = posX / 32;
	int y = posY / 32;
	bool remove=false;
	int re=0;
	

			tempBlock = createBlock(type, rot);

			if(tempBlock != NULL)
			{
				if(type == 3)
					entryDoor = tempBlock;
				block[nBlocks] = tempBlock;
				block[nBlocks]->SetPosition(16+x*32.0f, 16+y*32.0f); //lägger till nytt block
				for(int i=0;i<nBlocks;i++)
				{

						if(tempBlock->GetPosition()==block[i]->GetPosition()) //ifall redan finns block där du klickar och om det är av samma typ
						{														// som det du försöker sätta ut, ta bort det blocket
							if(typeid(*tempBlock)==typeid(*block[i]))
								{
									block[i]=block[nBlocks-1];
									nBlocks--;
									remove=true;
									re=-1;
									nPBlocks++;
								}
						}
				}
					if(remove==false)
					{
						if(nPBlocks>0){
						nBlocks++;
						re=1;
						nPBlocks--;
						}
					}
				tempBlock = NULL;
				delete tempBlock;

			}
			return re;
}