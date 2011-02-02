#ifndef BLOCK_H
#define BLOCK_H
#include <SFML\Graphics.hpp>
#include "ImgHolder.h"

enum blocktype{eSolid, eStandard, eTrampoline, eSmokebomb};

using namespace sf;

class Block:public Sprite
{
private:
	
public:
	Block();
	virtual ~Block() = 0;
	//Kollisionsfunktioner osvosv 

};

#endif