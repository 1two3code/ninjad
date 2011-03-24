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

NinjaHolder::NinjaHolder(int nr, int type, int state, Block* entryDoor)
{
	nrOfNinjas = nr;
	ninjaType=type;
	startState=state;
	ninjas = new NinjaIF*[nrOfNinjas];
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
		//cout<<ninjas[i]->getState()<<endl;
		switch(ninjas[i]->getState())
		{
		case 0:
			ninjas[i]->curAnim->sprite.SetPosition(entryDoor->curAnim->sprite.GetPosition().x+16+16*i, entryDoor->curAnim->sprite.GetPosition().y + (entryDoor->curAnim->sprite.GetSize().y/2 - ninjas[i]->curAnim->sprite.GetSize().y/2));
			break;
		case 1:
			ninjas[i]->curAnim->sprite.SetPosition(entryDoor->curAnim->sprite.GetPosition().x + (entryDoor->curAnim->sprite.GetSize().x/2 - ninjas[i]->curAnim->sprite.GetSize().x/2), entryDoor->curAnim->sprite.GetPosition().y-16-16*i);
			break;
		case 2:
			ninjas[i]->curAnim->sprite.SetPosition(entryDoor->curAnim->sprite.GetPosition().x-16-16*i, entryDoor->curAnim->sprite.GetPosition().y - (entryDoor->curAnim->sprite.GetSize().y/2 - ninjas[i]->curAnim->sprite.GetSize().y/2));
			break;
		case 3:
			ninjas[i]->curAnim->sprite.SetPosition(entryDoor->curAnim->sprite.GetPosition().x - (entryDoor->curAnim->sprite.GetSize().x/2 - ninjas[i]->curAnim->sprite.GetSize().x/2), entryDoor->curAnim->sprite.GetPosition().y+16+16*i);
			break;
		case 4:
			ninjas[i]->curAnim->sprite.SetPosition(entryDoor->curAnim->sprite.GetPosition().x+16+16*i, entryDoor->curAnim->sprite.GetPosition().y - (entryDoor->curAnim->sprite.GetSize().y/2 - ninjas[i]->curAnim->sprite.GetSize().y/2));
			break;
		case 5:
			ninjas[i]->curAnim->sprite.SetPosition(entryDoor->curAnim->sprite.GetPosition().x - (entryDoor->curAnim->sprite.GetSize().x/2 - ninjas[i]->curAnim->sprite.GetSize().x/2), entryDoor->curAnim->sprite.GetPosition().y-16-16*i);
			break;
		case 6:
			ninjas[i]->curAnim->sprite.SetPosition(entryDoor->curAnim->sprite.GetPosition().x-16-16*i, entryDoor->curAnim->sprite.GetPosition().y + (entryDoor->curAnim->sprite.GetSize().y/2 - ninjas[i]->curAnim->sprite.GetSize().y/2));
			break;
		case 7:
			ninjas[i]->curAnim->sprite.SetPosition(entryDoor->curAnim->sprite.GetPosition().x + (entryDoor->curAnim->sprite.GetSize().x/2 - ninjas[i]->curAnim->sprite.GetSize().x/2), entryDoor->curAnim->sprite.GetPosition().y+16+16*i);
			break;
		case 8:
			ninjas[i]->curAnim->sprite.SetPosition(entryDoor->curAnim->sprite.GetPosition().x, entryDoor->curAnim->sprite.GetPosition().y-16-16*i);
			break;
		default:
			break;
		}
	}


}

NinjaHolder::~NinjaHolder()
{
	for(int i=0;i<nrOfNinjas;i++)
	{
		delete ninjas[i];
	}
	delete []ninjas;
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
