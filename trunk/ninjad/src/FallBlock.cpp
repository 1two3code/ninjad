#include "FallBlock.h"

FallBlock::FallBlock()
{
	cropX0 = 192;	//Positionerna på Block-kartan med alla blocksprites
	cropY0 = 0;
	cropX1 = 224;
	cropY1 = 32;

	SetImage(*ImgHolder::getInst()->blocks);
	this->SetSubRect(IntRect(cropX0, cropY0, cropX1, cropY1));
	SetCenter(16,16);
}

FallBlock::~FallBlock()
{

}