#ifndef GAME_H
#define GAME_H
#include "HUDisplay.h"
#include "ImgHolder.h"
#include "Collision.h"
#include "Level.h"
#include "NinjaHolder.h"
#include "Player.h"
#include "InputHandler.h"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>


using namespace sf;

class Game
{
private:
	RenderWindow* mainWnd;
	Sprite* background;
	HUDisplay* hud;
	Player* player;
	NinjaHolder* ninjhold;
	Level* mainLvl;
	Collision* collision;
	InputHandler* input;
	Sprite* pauseScreen;
	Sprite* completeScreen;
	Clock* clockHold;

	Sprite* mptr;
	
	unsigned short currLevel;
	unsigned short ninjasIn;
	unsigned short FPS;
	bool paused;
	bool reset;
	bool levelComplete;

	void checkCollision();
	bool update();
	void render();
	bool eventHandler(Event e);
	unsigned short getCompleteNinjas();

	bool isNextLevel();
	void showLevelComplete();

public:
	Game();
	~Game();
	bool init(int level);
	int run();
	void cleanUp();


};

#endif