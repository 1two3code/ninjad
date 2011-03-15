#include "ExitDoor.h"

ExitDoor::ExitDoor()
{
	//cropX0 = 64;	//Positionerna på Block-kartan med alla blocksprites
	//cropY0 = 0;
	//cropX1 = 96;
	//cropY1 = 32;
	this->idleAnim = new Animation(ImgHolder::getInst()->blocks, 8, 32, 32, 1, false, false);
	this->idleAnim->sprite.SetCenter(16,16);
	this->idleAnim->SetFrame(2);

	this->activeAnim = idleAnim;
	this->curAnim = idleAnim;
	/*SetImage(*ImgHolder::getInst()->blocks);
	this->SetSubRect(IntRect(cropX0, cropY0, cropX1, cropY1));
	SetCenter(16,16);*/
}
void ExitDoor::Update()
{

}

void ExitDoor::Animate()
{

}
ExitDoor::~ExitDoor()
{

}