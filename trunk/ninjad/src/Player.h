#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "ImgHolder.h"
#include "InputHandler.h"

class Player : public Sprite
{
private:
	InputHandler* input;
	int animFrame;
	int speedx;
	int speedy;
	int acceleration;
	bool grounded;
	bool hitWall;
	int animTimer;
	bool hitHead;
	bool nextToWall;
	int blocks;

public:
	Player();
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
	void setNextToWall(bool ntw);
};

#endif