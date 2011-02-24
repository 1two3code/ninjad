#ifndef HUDISPLAY_H
#define HUDISPLAY_H
#include "ImgHolder.h"
#include "InputHandler.h"
#include "Level.h"
#include "Player.h"
#include <SFML\Graphics.hpp>

using namespace sf;


class HUDisplay
{
private:
	InputHandler* ip;

	Sprite* HUDbg;
	Sprite* quitButton;
	Sprite* pauseButton;
	Sprite* resetButton;
	Sprite* soundButton;

	Font* font;
	String* levelText;
	String* minNinjaText;
	String* maxNinjaText;
	String* timeText;
	String* playerBlockText;
	String* springBlockText;
	String* fallBlockText;
	String* jumpBlockText;

	int bz;
	Clock* clk;
	

public:
	HUDisplay();
	~HUDisplay();

	void update(Level* lvl, Player* ply);
	void render(RenderWindow* rndwnd);
	void HUDClicked(RenderWindow* rndwnd);
	int HUDReleased(RenderWindow* rndwnd);

};

#endif