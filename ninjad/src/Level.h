#ifndef LEVEL_H
#define LEVEL_H
#include <SFML\Graphics.hpp>
#include "StdBlock.h"

using namespace sf;

class Level
{
private:
	int nBlocks;
	int maxBlocks;
	Block** block;

public:
	Level(int j);
	~Level();
	void render(RenderWindow* rnd);
	void generateBlocks(int j);
	int findType(Color col);
	Block* createBlock(int type);
};

#endif