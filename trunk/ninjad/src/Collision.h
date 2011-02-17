#ifndef COLLISION_H
#define COLLISION_H

#include"Level.h"
#include"NinjaIF.h"
#include<iostream>
#include<typeinfo>
using namespace std;

class Collision
{
private:
	bool collides;
	bool foothold;
	bool airborne;
	int savedstate;
public:
	Collision();
	~Collision();
	void ninja(Block** block, NinjaIF* ninja,int nBlocks);
	void ninjaHitsWall(NinjaIF* ninja);
	void ninjaHitsGround(NinjaIF* ninja);
};

#endif