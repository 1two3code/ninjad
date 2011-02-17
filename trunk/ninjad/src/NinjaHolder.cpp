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

NinjaHolder::NinjaHolder(int nr, int type, int state, Block** block, int nrOfBlocks)
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
	for(int j=0; j<nrOfBlocks; j++)
	{
		if(typeid(*block[j]) == typeid(EntryDoor))
		{
			for(int i = 0; i < nrOfNinjas; i++)
			{
				//cout<<ninjas[i]->getState()<<endl;
				switch(ninjas[i]->getState())
				{
				case 0:
					ninjas[i]->SetPosition(block[j]->GetPosition().x+16*i, block[j]->GetPosition().y + (block[j]->GetSize().y/2 - ninjas[i]->GetSize().y/2));
					break;
				case 1:
					ninjas[i]->SetPosition(block[j]->GetPosition().x + (block[j]->GetSize().x/2 - ninjas[i]->GetSize().x/2), block[j]->GetPosition().y-16*i);
					break;
				case 2:
					ninjas[i]->SetPosition(block[j]->GetPosition().x-16*i, block[j]->GetPosition().y - (block[j]->GetSize().y/2 - ninjas[i]->GetSize().y/2));
					break;
				case 3:
					ninjas[i]->SetPosition(block[j]->GetPosition().x - (block[j]->GetSize().x/2 - ninjas[i]->GetSize().x/2), block[j]->GetPosition().y+16*i);
					break;
				case 4:
					ninjas[i]->SetPosition(block[j]->GetPosition().x+16*i, block[j]->GetPosition().y - (block[j]->GetSize().y/2 - ninjas[i]->GetSize().y/2));
					break;
				case 5:
					ninjas[i]->SetPosition(block[j]->GetPosition().x - (block[j]->GetSize().x/2 - ninjas[i]->GetSize().x/2), block[j]->GetPosition().y-16*i);
					break;
				case 6:
					ninjas[i]->SetPosition(block[j]->GetPosition().x-16*i, block[j]->GetPosition().y + (block[j]->GetSize().y/2 - ninjas[i]->GetSize().y/2));
					break;
				case 7:
					ninjas[i]->SetPosition(block[j]->GetPosition().x + (block[j]->GetSize().x/2 - ninjas[i]->GetSize().x/2), block[j]->GetPosition().y+16*i);
					break;
				case 8:
					ninjas[i]->SetPosition(block[j]->GetPosition().x, block[j]->GetPosition().y-16*i);
					break;
				default:
					break;
				}
			}
		}
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
