#include "Animation.h"

Animation::Animation(std::string fileName)
{
	this->timeScale = 1.0f;
	this->curFrame = 0;

	int imgSize = 0;

	//Läs in data från fil
	std::ifstream file;
	file.open(fileName.c_str(), std::ios::binary);
	
	if(file.is_open())
	{
		file.read((char*)this->sX, sizeof(int));
		file.read((char*)this->sY, sizeof(int));
		file.read((char*)this->frames, sizeof(int));
		file.read((char*)this->frameDelay, sizeof(int));
		file.read((char*)imgSize, sizeof(int));

		file.read(this->src, imgSize);
		file.close();
	}
	else
		return;

	this->img = new sf::Image();
	this->img->LoadFromMemory(this->src, imgSize);

	delete this->src;

}

Animation::Animation(int sX, int sY, int frames, int delay, std::string imageFile)
{
	this->timeScale = 1.0f;
	this->curFrame = 0;

	this->sX = sX;
	this->sY = sY;
	this->frames = frames;
	this->frameDelay = delay;

	this->img = new sf::Image();
	this->img->LoadFromFile(imageFile);

	this->sprite->SetImage(*this->img);
	this->sprite->SetSubRect(sf::IntRect(0,0,sX,sY));
}
Animation::~Animation()
{
	delete this->img;
}

void Animation::setTimeScale(float ts)
{
	this->timeScale = ts;
	return;
}

void Animation::Update(int t)
{
	this->curFrame = t % this->frameDelay;
	this->sprite->SetSubRect(sf::IntRect(this->sX*this->curFrame-this->sX, 0, this->sX*this->curFrame, this->sY));
	return;
}

void Animation::setCurFrame(int f)
{
	this->curFrame = f;
	return;
}

void Animation::WriteToFile(std::string fileName)
{
	std::ofstream file;
	file.open(fileName.c_str(), std::ios::binary);
	if(file.is_open())
	{
		file.write((char*)this->sX, sizeof(int));
		file.write((char*)this->sY, sizeof(int));
		file.write((char*)this->frames, sizeof(int));
		file.write((char*)this->frameDelay, sizeof(int));
		file.write((char*)sizeof(&this->img), sizeof(int));

		file.write((char*)&this->img, sizeof(&this->img));
	}
	return;
}

sf::Sprite* Animation::getSprite()
{
	return this->sprite;
}



