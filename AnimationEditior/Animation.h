#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

class Animation
{
private:
	std::string fileName;
	sf::Image img;
	//int frameDelay;
	int frames;
	int curFrame;
	int sX, sY;
	unsigned int counter;
	sf::IntRect subRect;

public:
	Animation();
	Animation(std::string, int, int, int, int);
	~Animation();
	void Update();
	void IncreaseDelay();
	void DecreaseDelay();
	void Load(std::string, int, int, int);
	
	sf::Sprite sprite;
	int frameDelay;
};

#endif