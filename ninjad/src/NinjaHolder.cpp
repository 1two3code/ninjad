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

	/*
		Har påbörjat att försöka placera ut Ninjorna efter blockets(dörrens) rotationsvektorer VecFace och VecHead
		Ninjorna ska placeras med jämt mellanrum i rad motsatt VecFace och vandra i VecFace-riktning
		Ninjorna måste också flyttas i förhållande till VecHead så de hamnar på marken i korrekt höjd oavsett vilken vägg de står på
		Skickar med entryDoor som pekare till konstruktorn istället för att leta upp dörren med Block** block och nrOfBlocks.
	*/
	//int edvfx = entryDoor->getVecFace().x;
	//int edvfy = entryDoor->getVecFace().y;

	//int edvhx = entryDoor->getVecHead().x;
	//int edvhy = entryDoor->getVecHead().y;

	//for(int i = 0; i < nrOfNinjas; i++)
	//{
	//	ninjas[i]->SetPosition(entryDoor->curAnim->sprite.GetPosition().x-16*i*edvfx, entryDoor->curAnim->sprite.GetPosition().y + -1*edvhy*(entryDoor->curAnim->sprite.GetSize().y/2 - ninjas[i]->GetSize().y/2));

	//	std::cout << entryDoor->getVecFace().x << endl << entryDoor->getVecFace().y << endl;
	//	std::cout << entryDoor->curAnim->sprite.GetSize().x << endl << entryDoor->curAnim->sprite.GetSize().y << endl;
	//	std::cout << entryDoor->curAnim->sprite.GetPosition().x<< endl << entryDoor->curAnim->sprite.GetPosition().y << endl << endl;
	//	//ninjas[i]->SetPosition(entryDoor->curAnim->sprite.GetPosition().x + entryDoor->getVecFace().x*i*16 ,entryDoor->curAnim->sprite.GetPosition().y + entryDoor->getVecFace().y*i*16);
	//}
	////entryDoor->


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
