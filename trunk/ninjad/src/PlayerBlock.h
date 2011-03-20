#ifndef PLAYERBLOCK_H
#define PLAYERBLOCK_H
#include "Block.h"

class PlayerBlock:public Block
{
private:
	
public:
	PlayerBlock();
	void Update();
	void Animate();
	~PlayerBlock();
};

#endif