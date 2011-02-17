#include "player.h"

Player::Player()
{
	input = &InputHandler::getInstance();
	setAnimFrame(0);
	setSpeed(8);

	SetImage(*ImgHolder::getInst()->ninja);
	//SetSubRect(IntRect(0,0,31,31));
	SetPosition(208,112);

	this->SetCenter(16,16);
	//this->SetRotation(90);
	
	//SetCenter(0,0);
	
}

Player::~Player()
{
}

void Player::update(RenderWindow* wnd)
{
	int f = getAnimFrame();
	if(input->isPressRight(wnd))
		Move((float)getSpeed()*1, (float)getSpeed()*0);
	if(input->isPressLeft(wnd))
		Move((float)getSpeed()*-1, (float)getSpeed()*0);
	if(input->isPressJump(wnd))
		Move((float)getSpeed()*0, -(float)getSpeed()*2);
	if(input->isPressClick(wnd))
	{}//släng ut block
	SetSubRect(IntRect(f*32, 0, f*32+32, 32));
	f++;
	f %= 4;
	setAnimFrame(f);
}

void Player::testmove(RenderWindow* wnd)
{
	if(input->isPressRight(wnd))
		Move((float)getSpeed()*1, (float)getSpeed()*0);
	if(input->isPressLeft(wnd))
		Move((float)getSpeed()*-1, (float)getSpeed()*0);
	if(input->isPressJump(wnd))
		Move((float)getSpeed()*0, -(float)getSpeed()*2);
	if(input->isPressClick(wnd))
	{}//släng ut block
}

void Player::retrace(RenderWindow* wnd)
{
	if(input->isPressRight(wnd))
		Move(-(float)getSpeed()*1, -(float)getSpeed()*0);
	if(input->isPressLeft(wnd))
		Move(-(float)getSpeed()*-1, -(float)getSpeed()*0);
	if(input->isPressJump(wnd))
		Move(-(float)getSpeed()*0, (float)getSpeed()*2);
	if(input->isPressClick(wnd))
	{}//släng ut block
}

void Player::updateSprite(RenderWindow* wnd)
{
	if(input->isPressRight(wnd))
		FlipX(true);
	if(input->isPressLeft(wnd))
		FlipX(false);
	if(input->isPressJump(wnd))
	{}	//jump animation
	if(input->isPressClick(wnd))
	{} //block animation
}

int Player::getAnimFrame()
{
	return animFrame;
}

void Player::setAnimFrame(int f)
{
	animFrame = f;
}

int Player::getSpeed()
{
	return speed;
}

void Player::setSpeed(int s)
{
	speed = s;
}