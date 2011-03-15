#ifndef STDBLOCK_H
#define STDBLOCK_H
#include "Block.h"

class StdBlock:public Block
{
private:
	
public:
	StdBlock();
	void Update();
	void Animate();
	~StdBlock();
};

#endif