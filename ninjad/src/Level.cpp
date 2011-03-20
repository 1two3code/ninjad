#include "Level.h"
#include "Block.h"
#include "PlayerBlock.h"
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
	startPos = Vector2i(0,0);
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
	{
		if(block[i]->curAnim->sprite.GetPosition().x > 96 && block[i]->curAnim->sprite.GetPosition().x < 608 && block[i]->curAnim->sprite.GetPosition().y > 160 && block[i]->curAnim->sprite.GetPosition().y < 672)
		//if(block[i]->curAnim->sprite.GetPosition().x > 512)
		{
		block[i]->Update();
		rnd->Draw(block[i]->curAnim->sprite);
		}
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
				if(blockType == 2)
					exitDoor = tempBlock;
				if(blockType == 3)
					entryDoor = tempBlock;
				block[nBlocks] = tempBlock;
				block[nBlocks]->curAnim->sprite.SetPosition(64+16+i*32.0f, 128+16+j*32.0f);
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
	startPos = Vector2i(map->GetPixel(17,18).r*32, map->GetPixel(17,18).g*32);
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
		rtn = new PlayerBlock();
		rtn->SetRotation(rot);
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
Block* Level::getExitDoor()
{
	return exitDoor;
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

int Level::addBlock(int type, int posX, int posY, int rot,Player* player, NinjaHolder* ninjhold) //type används inte än
{

	Block* tempBlock;
	int x = posX / 32;
	int y = posY / 32;
	bool remove=false;
	bool occupied=true;
	bool blockThere=true;
	int re=0;
	

			tempBlock = createBlock(type, rot);

			if(tempBlock != NULL)
			{
				if(type == 3)
					entryDoor = tempBlock;
				block[nBlocks] = tempBlock;
				block[nBlocks]->curAnim->sprite.SetPosition(16+x*32.0f, 16+y*32.0f); //lägger till nytt block
				if(player->getAccel()<=0)
				{
				
				
				for(int i=0;i<nBlocks;i++)
				{

						if(tempBlock->curAnim->sprite.GetPosition()==block[i]->curAnim->sprite.GetPosition()) //ifall redan finns block där du klickar och om det är av samma typ
						{																					// som det du försöker sätta ut, ta bort det blocket
							//if(typeid(*tempBlock)==typeid(*block[i]))
							if(typeid(*block[i])==typeid(PlayerBlock))
							{
									block[i]=block[nBlocks-1];
									nBlocks--;
									remove=true;
									re=-1;
									nPBlocks++;
							}
							else if(typeid(*block[i])==typeid(FallBlock))
							{
									block[i]=block[nBlocks-1];
									nBlocks--;
									remove=true;
									re=-1;
									nFBlocks++;
							}
							else if(typeid(*block[i])==typeid(JumpBlock))
							{
									block[i]=block[nBlocks-1];
									nBlocks--;
									remove=true;
									re=-1;
									nJBlocks++;
							}
							else if(typeid(*block[i])==typeid(SpringBlock))
							{
									block[i]=block[nBlocks-1];
									nBlocks--;
									remove=true;
									re=-1;
									nSBlocks++;
							}
							else
							{
								blockThere=false;
							}
						}
						else
							{
								occupied=true;
								for(int i=0;i<ninjhold->getNr() && occupied==true;i++){
									occupied=false;
								if(ninjhold->getNinjas(i)->curAnim->sprite.GetPosition().x + ninjhold->getNinjas(i)->curAnim->sprite.GetSize().x/2 <= posX-player->curAnim->sprite.GetSize().x/2)
									occupied=true;
								if(ninjhold->getNinjas(i)->curAnim->sprite.GetPosition().x - ninjhold->getNinjas(i)->curAnim->sprite.GetSize().x/2 >= posX+player->curAnim->sprite.GetSize().x/2)
									occupied=true;
								if(ninjhold->getNinjas(i)->curAnim->sprite.GetPosition().y + ninjhold->getNinjas(i)->curAnim->sprite.GetSize().y/2 <= posY-player->curAnim->sprite.GetSize().y/2)				
									occupied=true;
								if((ninjhold->getNinjas(i)->curAnim->sprite.GetPosition().y - ninjhold->getNinjas(i)->curAnim->sprite.GetSize().y/2 >= posY+player->curAnim->sprite.GetSize().y/2)	)		
									occupied=true;
								
							}
						}
				}
					if(remove==false&& occupied==true && blockThere==true)
					{
						if(type==7)
						{
							if(nPBlocks>0){
							nBlocks++;
							re=1;
							nPBlocks--;
							}
						}

						else if(type == 4)
						{
							if(nSBlocks>0){
							nBlocks++;
							re=1;
							nSBlocks--;
							}
						}
						else if(type == 5)
						{
							if(nJBlocks>0){
							nBlocks++;
							re=1;
							nJBlocks--;
							}
						}
						else if(type == 6)
						{
							if(nFBlocks>0){
							nBlocks++;
							re=1;
							nFBlocks--;
							}
						}
						}
					}
				}
				tempBlock = NULL;
				delete tempBlock;

			
			return re;
}


Vector2i Level::getStartPos()
{
	return startPos;
}