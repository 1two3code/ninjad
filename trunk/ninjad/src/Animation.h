#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>

class Animation
{
private:
	sf::Image* img;
	int frameDelay;
	int frames;
	int curFrame;
	int sX, sY;
	unsigned int counter;
	sf::IntRect subRect;

	bool loop, isRunning, mirX, mirY;


public:
	bool done;

	sf::Sprite sprite;

	Animation();
	Animation(sf::Image* img, int frames, int sizeX, int sizeY, int frameDelay, bool loop, bool isRunning);
	~Animation();
	void Update();
	void SetFrame(int frame);
	void Loop(bool loop);
	void IsRunning(bool isRunning);
	void Reset();
	void MirX(bool mirX);
	void MirY(bool mirY);
};

#endif