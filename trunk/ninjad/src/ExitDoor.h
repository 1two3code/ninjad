#ifndef EXITDOOR_H
#define EXITDOOR_H

#include "Block.h"

class ExitDoor: public Block
{
private:
public:
	ExitDoor();
	void Update();
	void Animate();
	~ExitDoor();
};

#endif