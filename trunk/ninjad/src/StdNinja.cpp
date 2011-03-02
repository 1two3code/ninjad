#include "StdNinja.h"

StdNinja::StdNinja(int s)
{
	setAnimFrame(0);
	setActive(false);
	setState(s);		//<-- S�tter ocks� mirroredX, dirX och dirY
	setSpeed(2);
	setDrawn(false);
	setAnimTimer(0);
	setComplete(false);

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
	int t = getAnimTimer();
	Move((float)getSpeed()*getDirX(), (float)getSpeed()*getDirY());
	if(t==0)
	{
		SetSubRect(IntRect(f*16, 0, f*16+16, 16));
		f++;
		f %= 4;
		setAnimFrame(f);
	}
	t++;
	t %= 2;
	setAnimTimer(t);
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
		Alla ska kolla f�rst �t x sen �t (dirX, dirY) efter kollision
		case 0 och 6, (dirX, 1)
		case 1 och 7, (-1, dirY)
		case 2 och 4, (dirX, -1)
		case 3 och 5, (1, dirY)
	*/
	switch(getState())
	{
	case 0:		//riktning �t v�nster, huvudet upp
		setMirroredX(false);
		SetRotation(0);
		setDirX(-1);
		setDirY(0);
		break;
	case 1:		//riktning Ner�t, huvudet �t v�nster
		setMirroredX(false);
		SetRotation(90);
		setDirX(0);
		setDirY(1);
		break;
	case 2:		//riktning h�ger, huvudet ner�t
		setMirroredX(false);
		SetRotation(180);
		setDirX(1);
		setDirY(0);
		break;
	case 3:		//riktning upp�t, huvudet �t h�ger
		setMirroredX(false);
		SetRotation(-90);
		setDirX(0);
		setDirY(-1);
		break;
	case 4:		//riktning v�nster, huvudet ner�t
		setMirroredX(true);
		SetRotation(180);
		setDirX(-1);
		setDirY(0);
		break;
	case 5:		//riktning ner�t, huvudet �t h�ger
		setMirroredX(true);
		SetRotation(-90);
		setDirX(0);
		setDirY(1);
		break;
	case 6:		//riktning h�ger, huvudet upp�t
		setMirroredX(true);
		SetRotation(0);
		setDirX(1);
		setDirY(0);
		break;
	case 7:		//riktning upp�t, huvudet �t v�nster
		setMirroredX(true);
		SetRotation(90);
		setDirX(0);
		setDirY(-1);
		break;
	case 8:		//faller ner�t, ingen spegling, ingen rotation
		setDirX(0);
		setDirY(1);
		break;
	case 9:		//flyger upp�t
		setDirX(0);
		setDirY(-1);
		break;
	default:
		break;

	}
}