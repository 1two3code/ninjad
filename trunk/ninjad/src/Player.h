#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "ImgHolder.h"
#include "InputHandler.h"
#include <iostream>
using namespace std;

class Player : public Sprite
{
private:
	InputHandler* input;
	int animFrame;
	int speedx;
	int speedy;
	int acceleration;
	int animTimer;
	int blocks;
	Sprite* hand;
	bool bugmode;
	bool grounded;
	bool nextToWall;
	bool direction; //false=left true=right
	bool hitRight;
	bool hitLeft;

public:
	Player(Vector2i pos);
	~Player();
	void setAnimFrame(int f);
	int getAnimFrame();
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
	void setHitRight(bool hit);
	void setHitLeft(bool hit);
	Sprite* getHand();
};

#endif