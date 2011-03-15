#ifndef JUMPBLOCK_H
#define JUMPBLOCK_H

#include "Block.h"

class JumpBlock: public Block
{
private:
public:
	JumpBlock();
	void Update();
	void Animate();
	~JumpBlock();
};

#endif