#ifndef HUDISPLAY_H
#define HUDISPLAY_H
#include "ImgHolder.h"
#include "InputHandler.h"
#include <SFML\Graphics.hpp>

using namespace sf;


class HUDisplay
{
private:
	Sprite* HUDbg;
	Sprite* quitButton;
	Sprite* pauseButton;
	Sprite* resetButton;
	Sprite* soundButton;

	int bz;		//ButtonSize
	//Knapparna
	//Time
	//Antal ninjor
	//Antal block
	//Levelnummer

public:
	HUDisplay();
	~HUDisplay();

	void render(RenderWindow* rndwnd);
	void HUDClicked(RenderWindow* rndwnd);
	void HUDReleased(RenderWindow* rndwnd);

};

#endif