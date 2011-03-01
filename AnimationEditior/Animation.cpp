#include "Animation.h"

Animation::Animation()
{
	
}

Animation::Animation(std::string fileName, int frames, int sizeX, int sizeY, int frameDelay)
{
	this->fileName = fileName;
	this->frames = frames;
	this->sX = sizeX;
	this->sY = sizeY;

	this->counter = 0;
	this->curFrame = 0;
	this->frameDelay = frameDelay;
	
	this->img.LoadFromFile(this->fileName);
	this->sprite.SetImage(this->img);
	this->subRect = sf::IntRect(0, 0, this->sX, this->sY);
	this->sprite.SetSubRect(this->subRect);
}

Animation::~Animation()
{

}

void Animation::Update()
{
	this->counter++;
	this->curFrame = (this->counter / this->frameDelay) % this->frames;

	int top = 0;
	int bottom = this->sY;
	int left = this->sX * curFrame;
	int right = this->sX * curFrame + this->sX;

	this->subRect = sf::IntRect(left, top, right, bottom);
	this->sprite.SetSubRect(this->subRect);
}

void Animation::IncreaseDelay()
{
	this->frameDelay++;

	this-> counter = 0;
}

void Animation::DecreaseDelay()
{
	if(this->frameDelay > 1)
		this->frameDelay--;

	this->counter = 0;
}

void Animation::Load(std::string fileName, int frames, int sizeX, int sizeY)
{
	if(this->img.LoadFromFile(fileName))
	{
		this->fileName = fileName;
		this->frames = frames;
		this->sX = sizeX;
		this->sY = sizeY;

		this->counter = 0;
		this->curFrame = 0;

		this->sprite.SetImage(this->img);
		this->subRect = sf::IntRect(0, 0, this->sX, this->sY);
		this->sprite.SetSubRect(this->subRect);
	}

	else
		this->img.LoadFromFile(this->fileName);
}

