#ifndef STDNINJA_H
#define STDNINJA_H
#include "NinjaIF.h"
#include "ImgHolder.h"
#include "Animation.h"

class StdNinja:public NinjaIF
{
private:

public:
	StdNinja(int s);
	~StdNinja();

	void update();
	void updateSprite();
	void testmove();
	void retrace();
};

#endif