#ifndef BLOCK_H
#define BLOCK_H
#include <cmath>
#include <SFML\Graphics.hpp>
#include "ImgHolder.h"

enum blocktype{eSolid, eStandard, eSpring, eJump, eEntry, eExit};

using namespace sf;

class Block:public Sprite
{
private:

protected:
	int cropX0, cropX1, cropY0, cropY1;
	Vector2i vecHead;			//Vector som pekar på vilket håll toppen a huvudet är
	Vector2i vecFace;			//-||- ansiktet 
	
public:
	Block();
	virtual ~Block() = 0;
	virtual void SetRotation(int rot);

	virtual Vector2i getVecHead();
	virtual Vector2i getVecFace();
	//Kollisionsfunktioner osvosv 

};

#endif