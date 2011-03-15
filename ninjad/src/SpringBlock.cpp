#include "SpringBlock.h"

SpringBlock::SpringBlock()
{
	//cropX0 = 128;	//Positionerna på Block-kartan med alla blocksprites
	//cropY0 = 0;
	//cropX1 = 160;
	//cropY1 = 32;
	this->idleAnim = new Animation(ImgHolder::getInst()->blocks, 8, 32, 32, 1, false, false);
	this->idleAnim->sprite.SetCenter(16,16);
	this->idleAnim->SetFrame(4);

	this->activeAnim = new Animation(ImgHolder::getInst()->blocks, 8, 32, 32, 1, false, false);
	this->activeAnim->sprite.SetCenter(16,16);
	this->activeAnim->SetFrame(2);

	this->curAnim = idleAnim;

	/*SetImage(*ImgHolder::getInst()->blocks);
	this->SetSubRect(IntRect(cropX0, cropY0, cropX1, cropY1));
	SetCenter(16,16);*/
}
void SpringBlock::Update()
{

}

void SpringBlock::Animate()
{

}

SpringBlock::~SpringBlock()
{

}