#include "player.h"

Player::Player(Vector2i pos)
{
	hand = new Sprite();
	hand->SetImage(*ImgHolder::getInst()->hand);

	precollides=false;
	input = &InputHandler::getInstance();
	setAnimFrame(0);
	setSpeedX(6);
	setSpeedY(0);
	setAccel(0);
	animTimer=0;
	this->setBugMode(false);
	this->setGrounded(true);
	nextToWall=false;
	direction=false;
	hitLeft=false;
	hitRight=false;
	setSizeX(16);
	setSizeY(26);
	
	SetImage(*ImgHolder::getInst()->player);

	//SetSubRect(IntRect(0,0,24,24));
	SetPosition(80+pos.x,144+pos.y); //5x17
	setPosX(this->GetPosition().x);
	setPosY(this->GetPosition().y + (this->GetSize().y - this->getSizeY())/2);

	this->SetCenter(1.5*getSizeX(), GetSize().y/2);
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
	if(input->isPressRight(wnd) && !input->isPressLeft(wnd) && !hitRight)
	{
			Move((float)getSpeedX()*1, (float)getSpeedY()*0);
			this->speedx=6;
			direction=true;
			setPosX(this->GetPosition().x);
			setPosY(this->GetPosition().y + (this->GetSize().y - this->getSizeY())/2);
	}
	if(input->isPressLeft(wnd) && !input->isPressRight(wnd) && !hitLeft)
	{
			Move((float)getSpeedX()*-1, (float)getSpeedY()*0);
			this->speedx=6;
			direction=false;
			setPosX(this->GetPosition().x);
			setPosY(this->GetPosition().y + (this->GetSize().y - this->getSizeY())/2);
	}
	Move((float)0, (float)getSpeedY());
	if(input->isPressJump(wnd) && grounded)
	{
		setSpeedY(-9);
		setAccel(1);
		this->bugmode=true;
		setGrounded(false);
		this->setPreCollides(false);
	}
	setSpeedY(getSpeedY()+getAccel());
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
	//if(bugmode) cin.get();
}

void Player::testmove(RenderWindow* wnd)
{
	if(input->isPressRight(wnd) && !input->isPressLeft(wnd))
	{
		Move((float)getSpeedX()*1, (float)getSpeedY()*0);
		setPosX(this->GetPosition().x);
		setPosY(this->GetPosition().y + (this->GetSize().y - this->getSizeY())/2);
	}
	if(input->isPressLeft(wnd) && !input->isPressRight(wnd))
	{
		Move((float)getSpeedX()*-1, (float)getSpeedY()*0);
		setPosX(this->GetPosition().x);
		setPosY(this->GetPosition().y + (this->GetSize().y - this->getSizeY())/2);
	}
	if(input->isPressClick(wnd))
	{}//släng ut block
}

void Player::testmoveY(RenderWindow* wnd)
{
	Move(0, (float)getSpeedY());
	setPosX(this->GetPosition().x);
	setPosY(this->GetPosition().y + (this->GetSize().y - this->getSizeY())/2);
}

void Player::retraceY(RenderWindow* wnd)
{
	Move(0, -(float)getSpeedY());
	setPosX(this->GetPosition().x);
	setPosY(this->GetPosition().y + (this->GetSize().y - this->getSizeY())/2);
}

void Player::retrace(RenderWindow* wnd)
{
	if(input->isPressRight(wnd)&& !input->isPressLeft(wnd))
	{
		Move(-(float)getSpeedX()*1, -(float)getSpeedY()*0);
		setPosX(this->GetPosition().x);
		setPosY(this->GetPosition().y + (this->GetSize().y - this->getSizeY())/2);
	}
	if(input->isPressLeft(wnd) && !input->isPressRight(wnd))
	{
		Move(-(float)getSpeedX()*-1, -(float)getSpeedY()*0);
		setPosX(this->GetPosition().x);
		setPosY(this->GetPosition().y + (this->GetSize().y - this->getSizeY())/2);
	}
	if(input->isPressClick(wnd))
	{}//släng ut block
}

void Player::updateSprite(RenderWindow* wnd)
{
	if(input->isPressRight(wnd) && !input->isPressLeft(wnd))
	{
		FlipX(true);
		this->SetCenter(1.5*getSizeX(), GetSize().y/2);
	}
	if(input->isPressLeft(wnd) && !input->isPressRight(wnd))
	{
		FlipX(false);
		this->SetCenter(0.5*getSizeX(), GetSize().y/2);
	}
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

Sprite* Player::getHand()
{
	return hand;
}

void Player::setBugMode(bool mode)
{
	this->bugmode=mode;
}

void Player::setGrounded(bool value)
{
	this->grounded=value;
}

void Player::setNextToWall(bool wall)
{
	this->nextToWall=wall;
}

bool Player::getDirection()
{
	return direction;
}

bool Player::getGrounded()
{
	return this->grounded;
}

void Player::setHitLeft(bool hit)
{
	this->hitLeft=hit;
}

void Player::setHitRight(bool hit)
{
	this->hitRight=hit;
}

int Player::getPosX()
{
	return posX;
}

int Player::getPosY()
{
	return posY;
}

int Player::getSizeX()
{
	return sizeX;
}

int Player::getSizeY()
{
	return sizeY;
}

void Player::setPosX(int pos)
{
	this->posX=pos;
}

void Player::setPosY(int pos)
{
	this->posY=pos;
}

void Player::setSizeX(int size)
{
	this->sizeX=size;
}

void Player::setSizeY(int size)
{
	this->sizeY=size;
}

void Player::setPreCollides(bool val)
{
	this->precollides=val;
}

bool Player::getPreCollides()
{
	return precollides;
}