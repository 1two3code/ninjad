#ifndef BLOCK_H
#define BLOCK_H
#include <SFML\Graphics.hpp>
#include "ImgHolder.h"

enum blocktype{eSolid, eStandard, eSpring, eJump, eEntry, eExit};

using namespace sf;

class Block:public Sprite
{
private:
	
protected:
	int cropX0, cropX1, cropY0, cropY1;

public:
	Block();
	virtual ~Block() = 0;
	//Kollisionsfunktioner osvosv 

};

#endif