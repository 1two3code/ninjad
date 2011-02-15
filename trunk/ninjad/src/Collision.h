#ifndef COLLISION_H
#define COLLISION_H

#include"Block.h"
#include"NinjaIF.h"
#include<iostream>
using namespace std;

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