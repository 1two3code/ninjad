#ifndef MENU_H
#define MENU_H
#include "ImgHolder.h"
#include "InputHandler.h"
#include <iostream>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "SndHolder.h"

using namespace sf;

class Menu
{
private:
	RenderWindow* menuWnd;
	Sprite* background;

	Sprite** levelButtons;
	Sprite* mapPreview;
	Sprite* numbers;
	Sprite* quitButton;
	Sprite* htpButton;		//How to play knapp
	Sprite* howToPlayScreen;
	bool howToPlay;

	int buttonPointed;
	int buttonClicked;

	Vector2i btnFrame;

	InputHandler* input;
	unsigned short unlocked;
	
	bool switchBool(bool tf);

protected:
public:
	Menu();
	~Menu();

	void splashScreen();
	int levelSelect();

	int update();
	int eventHandler(Event e);
	void render();

	int checkMousePos();

	void Show(bool tf);

	void setUnlockedLevels(unsigned short levels);
};

#endif