#ifndef STDBLOCK_H
#define STDBLOCK_H
#include "Block.h"

class StdBlock:public Block
{
private:
	int cropX0, cropX1, cropY0, cropY1;
public:
	StdBlock();
	~StdBlock();
};

#endif