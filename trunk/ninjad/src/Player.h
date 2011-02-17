#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "ImgHolder.h"

class Player : public Sprite
{
private:
	int animFrame;
	int speed;
public:
	Player();
	~Player();
	void setAnimFrame(int f);
	int getAnimFrame();
	void setSpeed(int s);
	int getSpeed();
	void update(RenderWindow* wnd);
	void updateSprite(RenderWindow* wnd);
	void testmove(RenderWindow* wnd);
	void retrace(RenderWindow* wnd);
};

#endif