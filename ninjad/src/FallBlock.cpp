#include "FallBlock.h"

FallBlock::FallBlock()
{
	//cropX0 = 192;	//Positionerna på Block-kartan med alla blocksprites
	//cropY0 = 0;
	//cropX1 = 224;
	//cropY1 = 32;
	this->idleAnim = new Animation(ImgHolder::getInst()->blocks, 8, 32, 32, 1, false, false);
	this->idleAnim->sprite.SetCenter(16,16);
	this->idleAnim->SetFrame(4);

	this->activeAnim = new Animation(ImgHolder::getInst()->blkFallAct, 4, 32, 32, 2, false, true);
	this->activeAnim->sprite.SetCenter(16,16);

	this->curAnim = idleAnim;

	/*SetImage(*ImgHolder::getInst()->blocks);
	this->SetSubRect(IntRect(cropX0, cropY0, cropX1, cropY1));
	SetCenter(16,16);*/
}
void FallBlock::Update()
{
	if(!this->curAnim->done)
		this->curAnim->Update();
	else
	{
		this->curAnim->Reset();
		this->idleAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
		this->curAnim = this->idleAnim;
	}
}

void FallBlock::Animate()
{
	//this->activeAnim->Reset();
	this->activeAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
	this->curAnim = this->activeAnim;
	this->curAnim->IsRunning(true);
}
FallBlock::~FallBlock()
{

}