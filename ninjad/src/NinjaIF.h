#ifndef NINJAIF_H
#define NINJAIF_H
#include <SFML/Graphics.hpp>

using namespace sf;
class NinjaIF:public Sprite
{

protected:
	int animFrame;
	bool active;
	int state;
	bool mirroredX;
	int dirX;
	int dirY;
	int speed;
	int nr;
	bool drawn;
	int animTimer;
	bool complete;

public:
	NinjaIF();
	virtual ~NinjaIF() = 0;

	void setAnimFrame(int f);
	int getAnimFrame();
	void setActive(bool bl);
	bool isActive();
	void setState(int s);
	int getState();
	void setMirroredX(bool mx);
	bool isMirroredX();
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
	void setAnimTimer(int t);
	int getAnimTimer();
	void setComplete(bool c);
	bool getComplete();

	virtual void update() = 0;
	virtual void updateSprite() = 0;
	virtual void testmove() = 0;
	virtual void retrace() = 0;
};

#endif