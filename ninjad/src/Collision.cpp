#include "Collision.h"
#include "SndHolder.h"

Collision::Collision()
{
	collides=true;
	airborne=true;
	savedstate=0;
	f=0;
}

Collision::~Collision()
{}

void Collision::ninja(Block** block, NinjaIF* ninja, int nBlocks)
{
	//1. Passerar ninjan intro-dörren?
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==0)
				ninja->setDrawn(true);
		}
		break;
	case 1:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==90)
				ninja->setDrawn(true);
		}
		break;
	case 2:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==180)
				ninja->setDrawn(true);
		}
		break;
	case 3:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==-90)
				ninja->setDrawn(true);
		}
		break;
	case 6:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==0)
				ninja->setDrawn(true);
		}
		break;
	case 7:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==90)
				ninja->setDrawn(true);
		}
		break;
	case 4:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==180)
				ninja->setDrawn(true);
		}
		break;
	case 5:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==-90)
				ninja->setDrawn(true);
		}
		break;
	case 8:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==0)
				ninja->setDrawn(true);
		}
		break;
	default:
		break;
	}

	if(ninja->getDrawn() == true)
	{
	//2. Passerar ninjan EXIT-dörren?
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 1:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==90)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 2:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==180)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 3:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==-90)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 6:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 7:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==90)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 4:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==180)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 5:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==-90)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 8:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	default:
		break;
	}

	//Ska ninjan hoppa?! :D:D:D
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==0)
				{
				savedstate=ninja->getState();
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 1:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==90)
				{
				savedstate=ninja->getState();
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 2:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==180)
				{
				savedstate=ninja->getState();
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 3:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==-90)
				{
				savedstate=ninja->getState();
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 6:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==0)
				{
				savedstate=ninja->getState();
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 7:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==90)
				{
				savedstate=ninja->getState();
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 4:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==180)
				{
				savedstate=ninja->getState();
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 5:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==-90)
			{
				savedstate=ninja->getState();
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 8:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	default:
		break;
	}
	
	//Ska ninjan hoppa längdhopp?
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==0)
				{
				savedstate=ninja->getState();
				ninja->setState(10);
				block[i]->Animate();
			}
		}
		break;
	case 1:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==90)
				{
				savedstate=ninja->getState();
				ninja->setState(10);
				block[i]->Animate();
			}
		}
		break;
	case 2:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==180)
				{
				savedstate=ninja->getState();
				ninja->setState(10);
				block[i]->Animate();
			}
		}
		break;
	case 3:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==-90)
				{
				savedstate=ninja->getState();
				ninja->setState(10);
				block[i]->Animate();
			}
		}
		break;
	case 6:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==0)
				{
				savedstate=ninja->getState();
				ninja->setState(10);
				block[i]->Animate();
			}
		}
		break;
	case 7:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==90)
				{
				savedstate=ninja->getState();
				ninja->setState(10);
				block[i]->Animate();
			}
		}
		break;
	case 4:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==180)
				{
				savedstate=ninja->getState();
				ninja->setState(10);
				block[i]->Animate();
			}
		}
		break;
	case 5:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==-90)
			{
				savedstate=ninja->getState();
				ninja->setState(10);
				block[i]->Animate();
			}
		}
		break;
	case 8:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setState(10);
				block[i]->Animate();
			}
		}
		break;
	default:
		break;
	}

	//Fallblock under fötterna?!
	airborne=true;
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(FallBlock))
				ninja->setState(8);
		}
	case 1:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(FallBlock))
				ninja->setState(8);
		}
		break;
	case 2:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(FallBlock))
				ninja->setState(8);
		}
		break;
	case 3:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(FallBlock))
				ninja->setState(8);
		}
		break;
	case 6:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(FallBlock))
				ninja->setState(8);
		}
	case 7:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(FallBlock))
				ninja->setState(8);
		}
		break;
	case 4:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(FallBlock))
				ninja->setState(8);
		}
		break;
	case 5:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(FallBlock))
				ninja->setState(8);
		}
		break;
	case 8:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(FallBlock))
				ninja->setState(8);
		}
		break;
	case 9:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(FallBlock))
				ninja->setState(8);
		}
		break;
	default:
		break;
	}

	//3. Har blocket under fötterna försvunnit?
	//cout<<"State before check: "<<ninja->getState()<<endl;
	airborne=true;
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				airborne=false;
		}
	case 1:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				airborne=false;
		}
		break;
	case 2:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				airborne=false;
		}
		break;
	case 3:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				airborne=false;
		}
		break;
	case 6:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				airborne=false;
		}
	case 7:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				airborne=false;
		}
		break;
	case 4:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				airborne=false;
		}
		break;
	case 5:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				airborne=false;
		}
		break;
	case 8:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
		break;
	case 9:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				airborne=false;
		}
		break;
	default:
		break;
	}

	if(airborne && ninja->getState()!=8 && ninja->getState()!=9 && ninja->getState()!=10 && ninja->getDrawn() == true)
	{
		savedstate=ninja->getState();
		ninja->setState(8);
	}

	else if(!airborne && ninja->getState()==8 && ninja->getDrawn() == true)
	{
		this->ninjaHitsGround(ninja);
	}

	else if(!airborne && ninja->getState()==9 && ninja->getDrawn() == true)
	{
		this->ninjaHitsHead(ninja);
	}
	
	//cout<<"State after check: "<<ninja->getState()<<endl;

	//4. Krock med vägg
	if(ninja->getState() != 8 && ninja->getState() != 9 && ninja->getState() != 10)
	{
		this->collides=false;
		ninja->testmove();
		for(int i=0; i<nBlocks && collides==false;i++)
		{
			this->collides=true;
		
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2)//Ninjan är till vänster om blocket
				collides=false;
			if(ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2)//Ninjan är till höger om blocket
				collides=false;
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2)//Ninjan är ovanför blocket
				collides=false;
			if(ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2)//Ninjan är nedanför blocket
				collides=false;
			if(typeid(*block[i]) != typeid(StdBlock) || ninja->getDrawn() != true) //Blocket är inte ett StdBlock
				collides=false;
		}
		ninja->retrace();
		if(collides)
			ninjaHitsWall(ninja);
	}

	//4,5. Krock med vägg (längdhopp)
	if(ninja->getState()==10)
	{
		this->collides=false;
		for(int i=0; i<nBlocks && collides==false;i++)
		{
			if(ninja->getDirX()==1 && ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) && ninja->curAnim->sprite.GetPosition().y > block[i]->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) && ninja->curAnim->sprite.GetPosition().y < block[i]->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) && typeid(*block[i]) == typeid(StdBlock))
			{
				collides=true;
				ninja->setState(7);
				int holder=ninja->curAnim->sprite.GetPosition().y;
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, (ninja->curAnim->sprite.GetPosition().y + (holder % 4)));
			}
			else if(ninja->getDirX()==-1 && ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) && ninja->curAnim->sprite.GetPosition().y > block[i]->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) && ninja->curAnim->sprite.GetPosition().y < block[i]->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) && typeid(*block[i]) == typeid(StdBlock))
			{
				collides=true;
				ninja->setState(3);
				int holder=ninja->curAnim->sprite.GetPosition().y;
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, (ninja->curAnim->sprite.GetPosition().y + (holder % 4)));
			}
		}

	}

	//5. Gå över en kant
	if((((int)(ninja->curAnim->sprite.GetPosition().x)%(int)(block[0]->curAnim->sprite.GetSize().x) == 0) && ((int)ninja->getState()%2 == 0)) || (((int)(ninja->curAnim->sprite.GetPosition().y)%(int)(block[0]->curAnim->sprite.GetSize().y) == 0) && ((int)ninja->getState()%2 == 1)) && ninja->getState() != 8 && ninja->getState() != 9 && ninja->getState() != 10 && ninja->getDrawn() == true)
	{
		this->foothold=false;
		switch(ninja->getState())
		{
		case 0:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 + ninja->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2, ninja->curAnim->sprite.GetPosition().y);
				ninja->setState(1);
			}
			break;
		case 1:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 + ninja->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2);
				ninja->setState(2);
			}
			break;
		case 2:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 - ninja->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2, ninja->curAnim->sprite.GetPosition().y);
				ninja->setState(3);
			}
			break;
		case 3:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 - ninja->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2);
				ninja->setState(0);
			}
			break;
		case 4:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 - ninja->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2, ninja->curAnim->sprite.GetPosition().y);
				ninja->setState(7);
			}
			break;
		case 5:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 - ninja->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2);
				ninja->setState(4);
			}
			break;
		case 6:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 + ninja->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2, ninja->curAnim->sprite.GetPosition().y);
				ninja->setState(5);
			}
			break;
		case 7:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 + ninja->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2);
				ninja->setState(6);
			}
			break;
		default:
			break;
		}
	}
	}
}

void Collision::ninjaHitsWall(NinjaIF* ninja)
{
	switch(ninja->getState())
	{
	case 0:
			ninja->setState(3);
		break;
	case 1:
			ninja->setState(0);
		break;
	case 2:
			ninja->setState(1);
		break;
	case 3:
			ninja->setState(2);
		break;
	case 4:
			ninja->setState(5);
		break;
	case 5:
			ninja->setState(6);
		break;
	case 6:
			ninja->setState(7);
		break;
	case 7:
			ninja->setState(4);
		break;
	default:
		break;

	}
}

void Collision::ninjaHitsGround(NinjaIF* ninja)
{
	switch(this->savedstate)
	{
	case 0:
			ninja->setState(0);
		break;
	case 1:
			ninja->setState(0);
		break;
	case 2:
			ninja->setState(0);
		break;
	case 3:
			ninja->setState(0);
		break;
	case 4:
			ninja->setState(6);
		break;
	case 5:
			ninja->setState(6);
		break;
	case 6:
			ninja->setState(6);
		break;
	case 7:
			ninja->setState(6);
		break;
	default:
		break;

	}
}

void Collision::ninjaHitsHead(NinjaIF* ninja)
{
	switch(this->savedstate)
	{
	case 0:
			ninja->setState(4);
		break;
	case 1:
			ninja->setState(4);
		break;
	case 2:
			ninja->setState(4);
		break;
	case 3:
			ninja->setState(4);
		break;
	case 4:
			ninja->setState(2);
		break;
	case 5:
			ninja->setState(2);
		break;
	case 6:
			ninja->setState(2);
		break;
	case 7:
			ninja->setState(2);
		break;
	default:
		break;

	}
}

void Collision::player(Block** block, Player* player, int nBlocks, RenderWindow* wnd)
{
	f++;
	this->firstTime=true;
	this->savedSpeed=0;
	//cout<<"X: "<<player->getPosX()<<" Y: "<<player->getPosY()<<" Sx: "<<player->getSpeedX()<<" Sy: "<<player->getSpeedY()<<endl;
	//Golv/tak-test
	bool wallcollide=false;
	int knuffarN=0;

	this->collides=true;
	while(collides)
	{


		this->collides=false;
		for(int i=0;i<nBlocks;i++)
		{
			if(player->getPosX() > block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosX() < block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock))) //Kolliderar i x-led
			{
				if(player->getPosY() > block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosY() < block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2)) //Kolliderar i y-led
				{
					this->collides=true;
					knuffarN=block[i]->curAnim->sprite.GetPosition().x;
				}

			}
		}

		if(collides && player->getPosX() <= knuffarN)
		{
			player->curAnim->sprite.SetPosition(player->curAnim->sprite.GetPosition().x - 1, player->curAnim->sprite.GetPosition().y);
			player->setPosX(player->getPosX() - 1);
		}
		else if(collides && player->getPosX() > knuffarN)
		{
			player->curAnim->sprite.SetPosition(player->curAnim->sprite.GetPosition().x + 1, player->curAnim->sprite.GetPosition().y);
			player->setPosX(player->getPosX() + 1);
		}
	}


	this->collides=true;
	while(collides)
	{


		this->collides=false;
		player->testmove(wnd);
		for(int i=0;i<nBlocks;i++)
		{
			if(player->getPosX() > block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosX() < block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock))) //Kolliderar i x-led
			{
				if(player->getPosY() > block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosY() < block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2)) //Kolliderar i y-led
					this->collides=true;
			}
		}
		player->retrace(wnd);

		if(collides && player->getSpeedX() > 0)
		{
			player->setSpeedX(player->getSpeedX()-1);
			wallcollide=true;
		}

		else if(collides && player->getSpeedX() < 0)
		{
			player->setSpeedX(player->getSpeedX()+1);
			wallcollide=true;
		}
		
		else if(collides && player->getSpeedX() == 0)
		{
			collides=false;
		}
	}



	this->collides=true;
	while(collides)
	{
		this->collides=false;
		player->testmoveY(wnd);
		for(int i=0;i<nBlocks;i++)
		{
			if(player->getPosX() > block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosX() < block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock))) //Kolliderar i x-led
			{
				if(player->getPosY() > block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosY() < block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2)) //Kolliderar i y-led
					this->collides=true;
			}
		}
		player->retraceY(wnd);

		if(collides && player->getSpeedY() > 0)
		{
			if(firstTime)
			{
				savedSpeed=player->getSpeedY();
				firstTime=false;
			}
			player->setSpeedY(player->getSpeedY()-1);
		}
	
		else if(collides && player->getSpeedY() < 0)
		{
			if(firstTime)
			{
				savedSpeed=player->getSpeedY();
				firstTime=false;
			}
			player->setSpeedY(player->getSpeedY()+1);
		}

		else if(collides && player->getSpeedY() == 0)
		{
			collides=false;
		}
		
	}

	//Ground-check
	collides=false;
	for(int i=0;i<nBlocks;i++)
	{
		if(player->getPosY() == block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosX() > block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosX() < block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
		{
			collides=true;
		}
	}

	if(!collides)
	{
		if(player->getPreCollides())
			player->setSpeedY(1);
		player->setAccel(1);
		player->setSpeedX(4);
		player->setGrounded(false);
		player->setPreCollides(false);
	}
	else
	{
		player->setAccel(0);
		player->setSpeedX(6);
		player->setGrounded(true);
		player->setPreCollides(true);
	}

	//Roofcheck
	collides=false;
	for(int i=0;i<nBlocks;i++)
	{
		if(player->getPosY() == block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosX() > block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosX() < block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
		{
			collides=true;
		}
	}

	if(collides && player->getGrounded())
	{
		player->setAccel(0);
		player->setSpeedY(0);
		//player->setGrounded(true);
	}

	//Wall-check
	bool rightwall=false;
	bool leftwall=false;
	for(int i=0;i<nBlocks;i++)
	{
		if(player->getPosX() == block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosY() > block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosY() < block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
		{
			wallcollide=true;
			rightwall=true;
		}
		if(player->getPosX() == block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosY() > block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosY() < block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)))
		{
			wallcollide=true;
			leftwall=true;
		}
	}

	if(leftwall)
	{
		player->setHitLeft(true);
	}
	else
	{
		player->setHitLeft(false);
	}

	if(rightwall)
	{
		player->setHitRight(true);
	}
	else
	{
		player->setHitRight(false);
	}

	//cout<<"X: "<<player->getPosX()<<" Y: "<<player->getPosY()<<" Sx: "<<player->getSpeedX()<<" Sy: "<<player->getSpeedY()<<endl;
	//cout<<rightwall<<" "<<leftwall<<" "<<f<<endl;

}




bool Collision::isPlayerAtExit(Player* p, Block* d)
{
	if(p->curAnim->sprite.GetPosition().x > d->curAnim->sprite.GetPosition().x - d->curAnim->sprite.GetSize().x/2 && p->curAnim->sprite.GetPosition().x < d->curAnim->sprite.GetPosition().x + d->curAnim->sprite.GetSize().x/2 && p->curAnim->sprite.GetPosition().y + (p->curAnim->sprite.GetSize().y/2 - d->curAnim->sprite.GetSize().y/2) == d->curAnim->sprite.GetPosition().y )
	{
		return true;
	}
	return false;
}