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

	Block* entryDoor;

	unsigned short nLevel;
	unsigned short nNinjas;
	unsigned short nPBlocks;
	unsigned short nJBlocks;
	unsigned short nSBlocks;
	unsigned short nFBlocks;


public:
	Level(int j);
	~Level();
	void render(RenderWindow* rnd);
	void generateBlocks(int j);
	int findType(Color col);
	int findRotation(Color col, int type);
	Block* createBlock(int type, int rot);
	int getNr(); //En get-funktion i brist på andra idéer
	Block** getBlocks(); //En get-funktion i brist på andra idéer
	int addBlock(int type, int posX, int posY, int rot); // tar också bort block, returns 1 for add, -1 for remove nad 0 for no change
	Block* getEntryDoor();

	unsigned short getNLevel();
	unsigned short getNNinjas();
	unsigned short getNPBlocks();
	unsigned short getNJBlocks();
	unsigned short getNSBlocks();
	unsigned short getNFBlocks();
};

#endif