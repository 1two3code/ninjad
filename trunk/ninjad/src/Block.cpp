#include "Block.h"
#include <iostream>

Block::Block()
{
	vecHead.x = 0;
	vecHead.y = -1;

	vecFace.x = 1;
	vecFace.y = 0;
}

Block::~Block()
{

}

void Block::SetRotation(int rot)
{
	//std::cout << "ROTERAD" << std::endl;

	
//	Sprite::SetRotation(rot);
}


Vector2i Block::getVecFace()
{
	return vecFace;
}

Vector2i Block::getVecHead()
{
	return vecHead;
}