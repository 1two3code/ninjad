#ifndef NINJAIF_H
#define NINJAIF_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "SndHolder.h"

using namespace sf;
class NinjaIF
{

protected:
	bool active;
	int state;
	int dirX;
	int dirY;
	int speed;
	int nr;
	bool drawn;
	bool complete;
	int speedY;
	int count;
	bool underground;
	bool dead;
	int savedstate;

public:
	Animation *curAnim, *runAnim, *slideAnim, *fallAnim, *climbAnim, *armAnim, *deathAnim;
	NinjaIF();
	virtual ~NinjaIF() = 0;

	void setActive(bool bl);
	bool isActive();

	void setState(int s);
	int getState();

	void setDirX(int dx);
	int getDirX();

	void setDirY(int dy);
	int getDirY();

	void setSpeed(int s);
	int getSpeed();

	void setNr(int nr);
	int getNr();

	void setDrawn(bool draw);
	int getDrawn();

	void setComplete(bool c);
	bool getComplete();

	void setSpeedY(int sy);
	int getSpeedY();

	void setDead(bool dead);
	bool getDead();

	void setSavedState(int savedstate);
	int getSavedState();

	virtual void update() = 0;
	virtual void updateSprite() = 0;
	virtual void testmove() = 0;
	virtual void retrace() = 0;
};

#endif