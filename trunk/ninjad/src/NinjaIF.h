#ifndef NINJAIF_H
#define NINJAIF_H
#include <SFML/Graphics.hpp>

using namespace sf;
class NinjaIF:public Sprite
{

private:
	int animFrame;
	bool active;
	int state;
	bool mirroredX;
	int dirX;
	int dirY;
	int speed;

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

	virtual void update() = 0;
	virtual void updateSprite() = 0;
	virtual void testmove() = 0;
	virtual void retrace() = 0;
};

#endif