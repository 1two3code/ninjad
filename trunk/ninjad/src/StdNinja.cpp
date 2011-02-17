#include "StdNinja.h"

StdNinja::StdNinja(int s)
{
	setAnimFrame(0);
	setActive(false);
	setState(s);		//<-- Sätter också mirroredX, dirX och dirY
	setSpeed(8);
	setDrawn(false);

	SetImage(*ImgHolder::getInst()->ninja);
	SetSubRect(IntRect(0,0,16,16));
	SetPosition(208,112);
	//FlipX(true);
	this->SetCenter(8,8);
	//this->SetRotation(90);
	
	//SetCenter(0,0);
	
}

StdNinja::~StdNinja()
{}

void StdNinja::update()
{
	int f = getAnimFrame();
	Move((float)getSpeed()*getDirX(), (float)getSpeed()*getDirY());
	SetSubRect(IntRect(f*16, 0, f*16+16, 16));
	f++;
	f %= 4;
	setAnimFrame(f);
}

void StdNinja::testmove()
{
	Move((float)getSpeed()*getDirX(), (float)getSpeed()*getDirY());
}

void StdNinja::retrace()
{
	Move(-(float)getSpeed()*getDirX(), -(float)getSpeed()*getDirY());
}

void StdNinja::updateSprite()
{

	/*
		Alla ska kolla först åt x sen åt (dirX, dirY) efter kollision
		case 0 och 6, (dirX, 1)
		case 1 och 7, (-1, dirY)
		case 2 och 4, (dirX, -1)
		case 3 och 5, (1, dirY)
	*/
	switch(getState())
	{
	case 0:		//riktning Åt vänster, huvudet upp
		setMirroredX(false);
		SetRotation(0);
		setDirX(-1);
		setDirY(0);
		break;
	case 1:		//riktning Neråt, huvudet åt vänster
		setMirroredX(false);
		SetRotation(90);
		setDirX(0);
		setDirY(1);
		break;
	case 2:		//riktning höger, huvudet neråt
		setMirroredX(false);
		SetRotation(180);
		setDirX(1);
		setDirY(0);
		break;
	case 3:		//riktning uppåt, huvudet åt höger
		setMirroredX(false);
		SetRotation(-90);
		setDirX(0);
		setDirY(-1);
		break;
	case 4:		//riktning vänster, huvudet neråt
		setMirroredX(true);
		SetRotation(180);
		setDirX(-1);
		setDirY(0);
		break;
	case 5:		//riktning neråt, huvudet åt höger
		setMirroredX(true);
		SetRotation(-90);
		setDirX(0);
		setDirY(1);
		break;
	case 6:		//riktning höger, huvudet uppåt
		setMirroredX(true);
		SetRotation(0);
		setDirX(1);
		setDirY(0);
		break;
	case 7:		//riktning uppåt, huvudet åt vänster
		setMirroredX(true);
		SetRotation(90);
		setDirX(0);
		setDirY(-1);
		break;
	case 8:		//faller neråt, ingen spegling, ingen rotation
		setDirX(0);
		setDirY(1);
		break;
	default:
		break;

	}
}