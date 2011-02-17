#ifndef NINJAHOLDER_H
#define NINJAHOLDER_H

#include"StdNinja.h"

class NinjaHolder
{
private:
	int nrOfNinjas;
	int ninjaType;
	int startState;
	NinjaIF** ninjas;
public:
	NinjaHolder();
	NinjaHolder(int nr, int type, int state);
	~NinjaHolder();
	void setNr(int nr);
	int getNr();
	void setType(int type);
	int getType();
	void setState(int state);
	int getState();
	NinjaIF* getNinjas(int index);
};

#endif