#ifndef MENU_H
#define MENU_H
#include "ImgHolder.h"
#include "InputHandler.h"
#include <iostream>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

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

	int buttonPointed;
	int buttonClicked;

	Vector2i btnFrame;

	InputHandler* input;
	unsigned short unlocked;		//Tempor�r f�r att testa vilka som �r locked och inte

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
};

#endif