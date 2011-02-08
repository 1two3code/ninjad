#include "NinjaIF.h"

NinjaIF::NinjaIF()
{}

NinjaIF::~NinjaIF()
{}


void NinjaIF::setAnimFrame(int f)
{
	animFrame = f;
}
int NinjaIF::getAnimFrame()
{
	return animFrame;
}

void NinjaIF::setActive(bool bl)
{
	active = bl;
}
bool NinjaIF::isActive()
{
	return active;
}

void NinjaIF::setState(int s)
{
	state = s;
	updateSprite();
}
int NinjaIF::getState()
{
	return state;
}

void NinjaIF::setMirroredX(bool mx)
{
	mirroredX = mx;
	FlipX(mirroredX);
}
bool NinjaIF::isMirroredX()
{
	return mirroredX;
}

void NinjaIF::setDirX(int dx)
{
	dirX = dx;
}
int NinjaIF::getDirX()
{
	return dirX;
}

void NinjaIF::setDirY(int dy)
{
	dirY = dy;
}
int NinjaIF::getDirY()
{
	return dirY;
}

void NinjaIF::setSpeed(int s)
{
	speed = s;
}
int NinjaIF::getSpeed()
{
	return speed;
}