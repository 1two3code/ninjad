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
	bool foothold;
public:
	Collision();
	~Collision();
	void ninja(Block** block, NinjaIF* ninja,int nBlocks);
	void ninjaHitsWall(NinjaIF* ninja);
};

#endif