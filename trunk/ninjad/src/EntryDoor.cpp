#include "EntryDoor.h"

EntryDoor::EntryDoor()
{
	cropX0 = 96;	//Positionerna på Block-kartan med alla blocksprites
	cropY0 = 0;
	cropX1 = 128;
	cropY1 = 32;

	SetImage(*ImgHolder::getInst()->blocks);
	this->SetSubRect(IntRect(cropX0, cropY0, cropX1, cropY1));
	SetCenter(16,16);
}

EntryDoor::~EntryDoor()
{

}