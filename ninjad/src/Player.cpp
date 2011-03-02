#include "player.h"

Player::Player()
{
	hand = new Sprite();
	hand->SetImage(*ImgHolder::getInst()->hand);

	input = &InputHandler::getInstance();
	setAnimFrame(0);
	setSpeedX(8);
	setSpeedY(0);
	setAccel(0);
	setGrounded(true);
	setHitWall(false);
	animTimer=0;
	setHitHead(false);
	setNextToWall(false);

	SetImage(*ImgHolder::getInst()->player);

	//SetSubRect(IntRect(0,0,31,31));
	SetPosition(208,656);

	this->SetCenter(16,16);
	//this->SetRotation(90);
	
	//SetCenter(0,0);
	input = &InputHandler::getInstance();
}

Player::~Player()
{
}

void Player::update(RenderWindow* wnd)
{
	hand->SetPosition(Player::GetPosition().x,Player::GetPosition().y);
	int f = getAnimFrame();
	if(input->isPressRight(wnd) && hitWall==false)
	{
		if(nextToWall == false)
			Move((float)getSpeedX()*1, (float)getSpeedY()*0);
		nextToWall=false;
	}
	if(input->isPressLeft(wnd) && hitWall==false)
	{
		if(nextToWall == false)
			Move((float)getSpeedX()*-1, (float)getSpeedY()*0);
		nextToWall=false;
	}
	if(input->isPressJump(wnd) && this->getGrounded()==true && hitHead==false)
	{
		setSpeedY(-16);
		setAccel(2);
		setGrounded(false);
	}
	setSpeedY(getSpeedY()+getAccel());
	Move((float)0, (float)getSpeedY());

	if(input->isPressClick(wnd))
	{}//släng ut block
	if(animTimer==0)
	{
		SetSubRect(IntRect(f*32, 0, f*32+32, 32));
		f++;
		f %= 4;
		setAnimFrame(f);
	}
	animTimer++;
	animTimer %= 2;
}

void Player::testmove(RenderWindow* wnd)
{
	if(input->isPressRight(wnd))
		Move((float)getSpeedX()*1, (float)getSpeedY()*0);
	if(input->isPressLeft(wnd))
		Move((float)getSpeedX()*-1, (float)getSpeedY()*0);
	if(input->isPressClick(wnd))
	{}//släng ut block
}

void Player::retrace(RenderWindow* wnd)
{
	if(input->isPressRight(wnd))
		Move(-(float)getSpeedX()*1, -(float)getSpeedY()*0);
	if(input->isPressLeft(wnd))
		Move(-(float)getSpeedX()*-1, -(float)getSpeedY()*0);
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

int Player::getSpeedX()
{
	return speedx;
}

void Player::setSpeedX(int s)
{
	speedx = s;
}

int Player::getSpeedY()
{
	return speedy;
}

void Player::setSpeedY(int s)
{
	speedy = s;
}

int Player::getAccel()
{
	return this->acceleration;
}

void Player::setAccel(int a)
{
	this->acceleration = a;
}

void Player::setGrounded(bool g)
{
	this->grounded=g;
}

bool Player::getGrounded()
{
	return this->grounded;
}

void Player::setHitWall(bool h)
{
	this->hitWall=h;
}

bool Player::getHitWall()
{
	return this->hitWall;
}

void Player::setHitHead(bool head)
{
	this->hitHead=head;
}

bool Player::getHitHead()
{
	return this->hitHead;
}

void Player::setNextToWall(bool ntw)
{
	this->nextToWall = ntw;
}

Sprite* Player::getHand()
{
	return hand;
}