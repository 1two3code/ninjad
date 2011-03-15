#include "StdBlock.h"
//#include <iostream>
StdBlock::StdBlock()
{
	//cropX0 = 32;	//Positionerna på Block-kartan med alla blocksprites
	//cropY0 = 0;
	//cropX1 = 64;
	//cropY1 = 32;

	this->idleAnim = new Animation(ImgHolder::getInst()->blocks, 8, 32, 32, 1, false, false);
	this->idleAnim->sprite.SetCenter(16,16);
	this->idleAnim->SetFrame(1);

	this->activeAnim = idleAnim;
	this->curAnim = idleAnim;
	//SetImage(*ImgHolder::getInst()->blocks);
	//this->SetSubRect(IntRect(cropX0, cropY0, cropX1, cropY1));
	//SetCenter(16,16);
	//std::cout << this->GetSize().x << std::endl << this->GetSize().y;

	
}
void StdBlock::Update()
{

}

void StdBlock::Animate()
{

}


StdBlock::~StdBlock()
{

}