#ifndef BLOCK_H
#define BLOCK_H
#include <cmath>
#include <SFML\Graphics.hpp>
#include "ImgHolder.h"
#include "Animation.h"
#include "SndHolder.h"

enum blocktype{eSolid, eStandard, eSpring, eJump, eEntry, eExit, ePlayer};

using namespace sf;

class Block
{
private:
protected:
	int cropX0, cropX1, cropY0, cropY1;
	Vector2i vecHead;			//Vector som pekar på vilket håll toppen a huvudet är
	Vector2i vecFace;			//-||- ansiktet 
	
public:
	Animation* curAnim, *idleAnim, *activeAnim;
	Block();
	virtual ~Block() = 0;
	virtual void SetRotation(int rot);

	virtual void Update() = 0;
	virtual void Animate() = 0;
	virtual Vector2i getVecHead();
	virtual Vector2i getVecFace();


};

#endif