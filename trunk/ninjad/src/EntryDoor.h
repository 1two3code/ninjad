#ifndef ENTRYDOOR_H
#define ENTRYDOOR_H

#include "Block.h"

class EntryDoor: public Block
{
private:
public:
	EntryDoor();
	void Update();
	void Animate();
	~EntryDoor();
};

#endif