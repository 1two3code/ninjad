#include "NinjaIF.h"

NinjaIF::NinjaIF()
{}

NinjaIF::~NinjaIF()
{}

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

void NinjaIF::setNr(int nr)
{
	this->nr=nr;
}

int NinjaIF::getNr()
{
	return this->nr;
}

void NinjaIF::setDrawn(bool draw)
{
	this->drawn=draw;
}

int NinjaIF::getDrawn()
{
	return this->drawn;
}

void NinjaIF::setComplete(bool c)
{
	this->complete=c;
}

bool NinjaIF::getComplete()
{
	return complete;
}

void NinjaIF::setSpeedY(int sy)
{
	this->speedY=sy;
}

int NinjaIF::getSpeedY()
{
	return this->speedY;
}