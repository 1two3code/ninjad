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
	InputHandler* input; //what

	unsigned short currLevel;


public:
	Game();
	~Game();
	bool init(int level);
	bool run();
	void cleanUp();

	void checkCollision();
	bool update();
	void render();

	void updNinja();

};

#endif