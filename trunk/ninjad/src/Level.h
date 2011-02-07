#ifndef LEVEL_H
#define LEVEL_H
#include <SFML\Graphics.hpp>
#include "StdBlock.h"
#include "EntryDoor.h"
#include "ExitDoor.h"
#include "JumpBlock.h"
#include "SpringBlock.h"
#include "FallBlock.h"

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
	int findRotation(Color col, int type);
	Block* createBlock(int type, int rot);
};

#endif