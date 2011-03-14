#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "ImgHolder.h"
#include "InputHandler.h"
#include "Animation.h"
#include <iostream>
using namespace std;

class Player
{
private:
	InputHandler* input;
	int speedx;
	int speedy;
	int acceleration;
	int blocks;
	Sprite* hand;
	bool bugmode;
	bool grounded;
	bool nextToWall;
	bool direction; //false=left true=right
	bool hitRight;
	bool hitLeft;
	int posX;
	int posY;
	int sizeX;
	int sizeY;
	bool precollides;

public:
	Animation* curAnim;
	Animation* runAnim;
	Animation* idleAnim;
	Animation* jumpAnim;

	Player(Vector2i pos);
	~Player();
	void setSpeedX(int s);
	int getSpeedX();
	void setSpeedY(int s);
	int getSpeedY();
	void setAccel(int a);
	int getAccel();
	void setGrounded(bool g);
	bool getGrounded();
	void setHitWall(bool h);
	bool getHitWall();
	void setHitHead(bool head);
	bool getHitHead();
	void update(RenderWindow* wnd);
	void updateSprite(RenderWindow* wnd);
	void testmove(RenderWindow* wnd);
	void retrace(RenderWindow* wnd);
	void testmoveY(RenderWindow* wnd);
	void retraceY(RenderWindow* wnd);
	void setNextToWall(bool ntw);
	void setBugMode(bool mode);
	bool getDirection();
	void setDirection(bool dir);
	void setHitRight(bool hit);
	void setHitLeft(bool hit);
	Sprite* getHand();
	int getPosX();
	void setPosX(int pos);
	int getPosY();
	void setPosY(int pos);
	int getSizeX();
	void setSizeX(int size);
	int getSizeY();
	void setSizeY(int size);
	void setPreCollides(bool val);
	bool getPreCollides();
};

#endif