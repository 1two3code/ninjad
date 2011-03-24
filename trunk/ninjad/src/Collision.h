#ifndef COLLISION_H
#define COLLISION_H

#include"Player.h"
#include"PlayerBlock.h"
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
	bool firstTime;
	int savedSpeed;
	int f;
	int animerarN;
public:
	Collision();
	~Collision();
	void ninja(Block** block, NinjaIF* ninja, int nBlocks);
	void ninjaHitsWall(NinjaIF* ninja);
	void ninjaHitsGround(NinjaIF* ninja);
	void ninjaHitsHead(NinjaIF* ninja);
	void player(Block** block, Player* player, int nBlocks,RenderWindow* wnd);
	bool isPlayerAtExit(Player* player, Block* exitDoor);
};

#endif