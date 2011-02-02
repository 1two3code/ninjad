#ifndef GAME_H
#define GAME_H
#include "Level.h"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class Game
{
private:
	RenderWindow* mainWnd;
	Thread* mainThrd;
	//Sensei
	Level* mainLvl;
	Sprite* ninja;

	bool ninjago;
	int frame;
	
public:
	Game();
	~Game();
	bool init(int level);
	bool run();
	void cleanUp();

	bool update();
	void render();

	void updNinja();

};

#endif