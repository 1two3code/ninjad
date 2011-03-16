#include "JumpBlock.h"

JumpBlock::JumpBlock()
{
	//cropX0 = 160;	//Positionerna på Block-kartan med alla blocksprites
	//cropY0 = 0;
	//cropX1 = 192;
	//cropY1 = 32;
	this->idleAnim = new Animation(ImgHolder::getInst()->blocks, 8, 32, 32, 1, false, false);
	this->idleAnim->sprite.SetCenter(16,16);
	this->idleAnim->SetFrame(5);

	this->activeAnim = new Animation(ImgHolder::getInst()->blkSpringAct, 6, 32, 32, 1, false, false);
	this->activeAnim->sprite.SetCenter(16,16);
	this->activeAnim->SetFrame(5);

	this->curAnim = idleAnim;

	/*SetImage(*ImgHolder::getInst()->blocks);
	this->SetSubRect(IntRect(cropX0, cropY0, cropX1, cropY1));
	SetCenter(16,16);*/
}

void JumpBlock::Update()
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

void JumpBlock::Animate()
{
	SndHolder::getInst()->sndSpring.Play();
	this->activeAnim->Reset();
	this->activeAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
	this->curAnim = this->activeAnim;
	this->curAnim->IsRunning(true);
}
JumpBlock::~JumpBlock()
{

}