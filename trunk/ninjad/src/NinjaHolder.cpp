#include "NinjaHolder.h"

NinjaHolder::NinjaHolder()
{
	this->nrOfNinjas=15;
	this->ninjaType=0;
	this->startState=0;
	this->ninjas = new NinjaIF*[nrOfNinjas];
	for(int i=0;i<nrOfNinjas;i++)
	{
		if(ninjaType==0)
			ninjas[i] = new StdNinja(startState);
		else
			ninjas[i] = new StdNinja(startState);
	}
}

NinjaHolder::NinjaHolder(int nr, int type, int state)
{
	this->nrOfNinjas=nr;
	this->ninjaType=type;
	this->startState=state;
	this->ninjas = new NinjaIF*[nrOfNinjas];
	for(int i=0;i<nrOfNinjas;i++)
	{
		//Om vi vill ha olika ninja-typer
		if(ninjaType==0)
			ninjas[i] = new StdNinja(startState);
		else
			ninjas[i] = new StdNinja(startState);
	}
	for(int i = 0; i < nrOfNinjas; i++)
	{
		ninjas[i]->SetPosition(208+16*i,112);
	}
}

NinjaHolder::~NinjaHolder()
{
	for(int i=0;i<nrOfNinjas;i++)
	{
		delete ninjas[i];
	}
	delete ninjas;
}

void NinjaHolder::setNr(int nr)
{
	this->nrOfNinjas=nr;
}

int NinjaHolder::getNr()
{
	return this->nrOfNinjas;
}

void NinjaHolder::setType(int type)
{
	this->ninjaType=type;
}

int NinjaHolder::getType()
{
	return this->ninjaType;
}

void NinjaHolder::setState(int state)
{
	this->startState=state;
}

int NinjaHolder::getState()
{
	return this->startState;
}

NinjaIF* NinjaHolder::getNinjas(int index)
{
	return ninjas[index];
}
