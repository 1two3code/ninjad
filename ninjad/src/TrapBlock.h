#ifndef TRAPBLOCK_H
#define TRAPBLOCK_H

#include "Block.h"

class TrapBlock: public Block
{
private:
public:
	TrapBlock();
	void Update();
	void Animate();
	~TrapBlock();
};

#endif