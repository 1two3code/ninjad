#include "Animation.h"

Animation::Animation()
{
	
}

Animation::Animation(sf::Image* img, int frames, int sizeX, int sizeY, int frameDelay, bool loop, bool isRunning)
{
	this->done = false;

	this->frames = frames;
	this->sX = sizeX;
	this->sY = sizeY;

	this->counter = 0;
	this->curFrame = 0;
	this->frameDelay = frameDelay;
	
	this->img = img;
	this->sprite.SetImage(*this->img);
	this->subRect = sf::IntRect(0, 0, this->sX, this->sY);
	this->sprite.SetSubRect(this->subRect);

	this->loop = loop;
	this->isRunning = isRunning;

	this->mirX = false;
	this->mirY = false;
}

Animation::~Animation()
{

}

void Animation::Update()
{
	if((this->loop && this->isRunning) || (!this->loop && !this->done && this->isRunning))
	{
		this->counter++;
		this->curFrame = (this->counter / this->frameDelay) % this->frames;

		int top = 0;
		int bottom = this->sY;
		int left = this->sX * curFrame;
		int right = this->sX * curFrame + this->sX;

		this->subRect = sf::IntRect(left, top, right, bottom);
		this->sprite.SetSubRect(this->subRect);

			this->sprite.FlipX(mirX);
			this->sprite.FlipY(mirY);
		if((this->counter == this->frames * this->frameDelay) && !this->loop) this->done = true;
	}
}

void Animation::SetFrame(int frame)
{
	this->curFrame = frame;

	int top = 0;
	int bottom = this->sY;
	int left = this->sX * curFrame;
	int right = this->sX * curFrame + this->sX;

	this->subRect = sf::IntRect(left, top, right, bottom);
	this->sprite.SetSubRect(this->subRect);

		this->sprite.FlipX(mirX);
		this->sprite.FlipY(mirY);

	this->counter = (this->curFrame * this->frames * this->frameDelay) - (this->frameDelay * (this->frames-this->curFrame)) - (this->frameDelay-1);
}

void Animation::Loop(bool loop)
{
	this->loop = loop;
}

void Animation::IsRunning(bool isRunning)
{
	this->isRunning = isRunning;
}

void Animation::Reset()
{
	this->counter = 0;
	this->done = false;
}

void Animation::MirX(bool mirX)
{
	this->mirX = mirX;
}

void Animation::MirY(bool mirY)
{
	this->mirY = mirY;
}