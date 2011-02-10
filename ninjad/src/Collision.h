#ifndef COLLISION_H
#define COLLISION_H

#include"Game.h"
#include"Block.h"
#include"NinjaIF.h"

class Collision
{
private:
	bool collides;
public:
	Collision();
	~Collision();
	int ninja(Block** block, NinjaIF* ninja,int nBlocks);
};

#endif