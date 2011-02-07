#include "ExitDoor.h"

ExitDoor::ExitDoor()
{
	cropX0 = 64;	//Positionerna på Block-kartan med alla blocksprites
	cropY0 = 0;
	cropX1 = 96;
	cropY1 = 32;

	SetImage(*ImgHolder::getInst()->blocks);
	this->SetSubRect(IntRect(cropX0, cropY0, cropX1, cropY1));
	SetCenter(16,16);
}

ExitDoor::~ExitDoor()
{

}