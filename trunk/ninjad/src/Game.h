#ifndef GAME_H
#define GAME_H
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
	Thread* mainThrd;
	//NinjaIF** ninjas;
	Sprite* background;
	Player* player;
	NinjaHolder* ninjhold;
	Level* mainLvl;
	Collision* collision;
	InputHandler* input; //what

	int temp;

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