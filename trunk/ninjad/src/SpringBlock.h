#ifndef	SPRINGBLOCK_H
#define SPRINGBLOCK_H

#include "Block.h"

class SpringBlock: public Block
{
private:
public:
	SpringBlock();
	void Update();
	void Animate();
	~SpringBlock();
};

#endif