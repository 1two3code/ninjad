#include "StdBlock.h"
//#include <iostream>
StdBlock::StdBlock()
{
	cropX0 = 32;	//Positionerna på Block-kartan med alla blocksprites
	cropY0 = 0;
	cropX1 = 64;
	cropY1 = 32;

	SetImage(*ImgHolder::getInst()->blocks);
	this->SetSubRect(IntRect(cropX0, cropY0, cropX1, cropY1));
	SetCenter(16,16);
	//std::cout << this->GetSize().x << std::endl << this->GetSize().y;

	
}


StdBlock::~StdBlock()
{

}