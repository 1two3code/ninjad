#include "TrapBlock.h"

TrapBlock::TrapBlock()
{
	//cropX0 = 160;	//Positionerna på Block-kartan med alla blocksprites
	//cropY0 = 0;
	//cropX1 = 192;
	//cropY1 = 32;
	this->idleAnim = new Animation(ImgHolder::getInst()->blkTrapIdle, 8, 32, 32, 3, true, true);
	this->idleAnim->sprite.SetCenter(16,16);
	//this->idleAnim->SetFrame(8);

	this->activeAnim = NULL;
	this->curAnim = idleAnim;

	/*SetImage(*ImgHolder::getInst()->blocks);
	this->SetSubRect(IntRect(cropX0, cropY0, cropX1, cropY1));
	SetCenter(16,16);*/
}

void TrapBlock::Update()
{
	this->curAnim->Update();
}

void TrapBlock::Animate()
{
	
}
TrapBlock::~TrapBlock()
{


}