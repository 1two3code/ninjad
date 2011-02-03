#ifndef GAME_H
#define GAME_H
#include "Level.h"
#include "StdNinja.h"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class Game
{
private:
	RenderWindow* mainWnd;
	Thread* mainThrd;
	NinjaIF* ninjas;
	Level* mainLvl;

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