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
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y + (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->GetRotation()==ninja->GetRotation())
				ninja->setDrawn(true);
		}
		break;
	case 1:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x + (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->GetRotation()==ninja->GetRotation())
				ninja->setDrawn(true);
		}
		break;
	case 2:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y - (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->GetRotation()==ninja->GetRotation())
				ninja->setDrawn(true);
		}
		break;
	case 3:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x - (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->GetRotation()==ninja->GetRotation())
				ninja->setDrawn(true);
		}
		break;
	case 6:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y + (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->GetRotation()==ninja->GetRotation())
				ninja->setDrawn(true);
		}
		break;
	case 7:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x + (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->GetRotation()==ninja->GetRotation())
				ninja->setDrawn(true);
		}
		break;
	case 4:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y - (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->GetRotation()==ninja->GetRotation())
				ninja->setDrawn(true);
		}
		break;
	case 5:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x - (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->GetRotation()==ninja->GetRotation())
				ninja->setDrawn(true);
		}
		break;
	case 8:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y + (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->GetRotation()==ninja->GetRotation())
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
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y + (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->GetRotation()==ninja->GetRotation())
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
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x + (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->GetRotation()==ninja->GetRotation())
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
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y - (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->GetRotation()==ninja->GetRotation())
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
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x - (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->GetRotation()==-ninja->GetRotation())
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
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y + (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->GetRotation()==ninja->GetRotation())
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
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x + (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->GetRotation()==ninja->GetRotation())
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
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y - (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->GetRotation()==ninja->GetRotation())
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
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x - (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->GetRotation()==-ninja->GetRotation())
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
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y + (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->GetRotation()==ninja->GetRotation())
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
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y + (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->GetRotation()==ninja->GetRotation())
				{
				savedstate=ninja->getState();
				ninja->setState(9);
			}
		}
		break;
	case 1:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x + (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->GetRotation()==ninja->GetRotation())
				{
				savedstate=ninja->getState();
				ninja->setState(9);
			}
		}
		break;
	case 2:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y - (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->GetRotation()==ninja->GetRotation())
				{
				savedstate=ninja->getState();
				ninja->setState(9);
			}
		}
		break;
	case 3:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x - (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->GetRotation()==-ninja->GetRotation())
				{
				savedstate=ninja->getState();
				ninja->setState(9);
			}
		}
		break;
	case 6:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y + (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->GetRotation()==ninja->GetRotation())
				{
				savedstate=ninja->getState();
				ninja->setState(9);
			}
		}
		break;
	case 7:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x + (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->GetRotation()==ninja->GetRotation())
				{
				savedstate=ninja->getState();
				ninja->setState(9);
			}
		}
		break;
	case 4:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y - (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->GetRotation()==ninja->GetRotation())
				{
				savedstate=ninja->getState();
				ninja->setState(9);
			}
		}
		break;
	case 5:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().y == block[i]->GetPosition().y && ninja->GetPosition().x - (ninja->GetSize().x/2 - block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->GetRotation()==-ninja->GetRotation())
			{
				savedstate=ninja->getState();
				ninja->setState(9);
			}
		}
		break;
	case 8:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->GetPosition().x == block[i]->GetPosition().x && ninja->GetPosition().y + (ninja->GetSize().y/2 - block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->GetRotation()==ninja->GetRotation())
				ninja->setState(9);
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
			if(ninja->GetPosition().x + ninja->GetSize().x/2 >= block[i]->GetPosition().x - block[i]->GetSize().x/2 && ninja->GetPosition().x - ninja->GetSize().x/2 <= block[i]->GetPosition().x + block[i]->GetSize().x/2 && ninja->GetPosition().y + (ninja->GetSize().y/2 + block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
	case 1:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->GetPosition().y + ninja->GetSize().y/2 >= block[i]->GetPosition().y - block[i]->GetSize().y/2 && ninja->GetPosition().y - ninja->GetSize().y/2 <= block[i]->GetPosition().y + block[i]->GetSize().y/2 && ninja->GetPosition().x + (ninja->GetSize().x/2 + block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
		break;
	case 2:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->GetPosition().x + ninja->GetSize().x/2 >= block[i]->GetPosition().x - block[i]->GetSize().x/2 && ninja->GetPosition().x - ninja->GetSize().x/2 <= block[i]->GetPosition().x + block[i]->GetSize().x/2 && ninja->GetPosition().y - (ninja->GetSize().y/2 + block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
		break;
	case 3:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->GetPosition().y + ninja->GetSize().y/2 >= block[i]->GetPosition().y - block[i]->GetSize().y/2 && ninja->GetPosition().y - ninja->GetSize().y/2 <= block[i]->GetPosition().y + block[i]->GetSize().y/2 && ninja->GetPosition().x - (ninja->GetSize().x/2 + block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
		break;
	case 6:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->GetPosition().x + ninja->GetSize().x/2 >= block[i]->GetPosition().x - block[i]->GetSize().x/2 && ninja->GetPosition().x - ninja->GetSize().x/2 <= block[i]->GetPosition().x + block[i]->GetSize().x/2 && ninja->GetPosition().y + (ninja->GetSize().y/2 + block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
	case 7:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->GetPosition().y + ninja->GetSize().y/2 >= block[i]->GetPosition().y - block[i]->GetSize().y/2 && ninja->GetPosition().y - ninja->GetSize().y/2 <= block[i]->GetPosition().y + block[i]->GetSize().y/2 && ninja->GetPosition().x + (ninja->GetSize().x/2 + block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
		break;
	case 4:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->GetPosition().x + ninja->GetSize().x/2 >= block[i]->GetPosition().x - block[i]->GetSize().x/2 && ninja->GetPosition().x - ninja->GetSize().x/2 <= block[i]->GetPosition().x + block[i]->GetSize().x/2 && ninja->GetPosition().y - (ninja->GetSize().y/2 + block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
		break;
	case 5:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->GetPosition().y + ninja->GetSize().y/2 >= block[i]->GetPosition().y - block[i]->GetSize().y/2 && ninja->GetPosition().y - ninja->GetSize().y/2 <= block[i]->GetPosition().y + block[i]->GetSize().y/2 && ninja->GetPosition().x - (ninja->GetSize().x/2 + block[i]->GetSize().x/2) == block[i]->GetPosition().x && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
		break;
	case 8:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->GetPosition().x + ninja->GetSize().x/2 >= block[i]->GetPosition().x - block[i]->GetSize().x/2 && ninja->GetPosition().x - ninja->GetSize().x/2 <= block[i]->GetPosition().x + block[i]->GetSize().x/2 && ninja->GetPosition().y + (ninja->GetSize().y/2 + block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
		break;
	case 9:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->GetPosition().x + ninja->GetSize().x/2 >= block[i]->GetPosition().x - block[i]->GetSize().x/2 && ninja->GetPosition().x - ninja->GetSize().x/2 <= block[i]->GetPosition().x + block[i]->GetSize().x/2 && ninja->GetPosition().y - (ninja->GetSize().y/2 + block[i]->GetSize().y/2) == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				airborne=false;
		}
		break;
	default:
		break;
	}

	if(airborne && ninja->getState()!=8 && ninja->getState()!=9 && ninja->getDrawn() == true)
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
	if(ninja->getState() != 8 && ninja->getState() != 9)
	{
	this->collides=false;
	ninja->testmove();
	for(int i=0; i<nBlocks && collides==false;i++)
	{
		this->collides=true;
		
		if(ninja->GetPosition().x + ninja->GetSize().x/2 <= block[i]->GetPosition().x - block[i]->GetSize().x/2)//Ninjan är till vänster om blocket
			collides=false;
		if(ninja->GetPosition().x - ninja->GetSize().x/2 >= block[i]->GetPosition().x + block[i]->GetSize().x/2)//Ninjan är till höger om blocket
			collides=false;
		if(ninja->GetPosition().y + ninja->GetSize().y/2 <= block[i]->GetPosition().y - block[i]->GetSize().y/2)//Ninjan är ovanför blocket
			collides=false;
		if(ninja->GetPosition().y - ninja->GetSize().y/2 >= block[i]->GetPosition().y + block[i]->GetSize().y/2)//Ninjan är nedanför blocket
			collides=false;
		if(typeid(*block[i]) != typeid(StdBlock) || ninja->getDrawn() != true) //Blocket är inte ett StdBlock
			collides=false;
	}
	ninja->retrace();
	if(collides)
		ninjaHitsWall(ninja);
	}

	//5. Gå över en kant
	if((((int)(ninja->GetPosition().x)%(int)(block[0]->GetSize().x) == 0) && ((int)ninja->getState()%2 == 0)) || (((int)(ninja->GetPosition().y)%(int)(block[0]->GetSize().y) == 0) && ((int)ninja->getState()%2 == 1)) && ninja->getState() != 8 && ninja->getState() != 9 && ninja->getDrawn() == true)
	{
		this->foothold=false;
		switch(ninja->getState())
		{
		case 0:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->GetPosition().x - block[i]->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y + block[i]->GetSize().y/2 + ninja->GetSize().y/2 == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->SetPosition(ninja->GetPosition().x - ninja->GetSize().x/2, ninja->GetPosition().y);
				ninja->setState(1);
			}
			break;
		case 1:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->GetPosition().x + block[i]->GetSize().x/2 + ninja->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y + block[i]->GetSize().y/2 == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->SetPosition(ninja->GetPosition().x, ninja->GetPosition().y + ninja->GetSize().y/2);
				ninja->setState(2);
			}
			break;
		case 2:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->GetPosition().x + block[i]->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y - block[i]->GetSize().y/2 - ninja->GetSize().y/2 == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->SetPosition(ninja->GetPosition().x + ninja->GetSize().x/2, ninja->GetPosition().y);
				ninja->setState(3);
			}
			break;
		case 3:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->GetPosition().x - block[i]->GetSize().x/2 - ninja->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y - block[i]->GetSize().y/2 == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->SetPosition(ninja->GetPosition().x, ninja->GetPosition().y - ninja->GetSize().y/2);
				ninja->setState(0);
			}
			break;
		case 4:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->GetPosition().x - block[i]->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y - block[i]->GetSize().y/2 - ninja->GetSize().y/2 == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->SetPosition(ninja->GetPosition().x - ninja->GetSize().x/2, ninja->GetPosition().y);
				ninja->setState(7);
			}
			break;
		case 5:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->GetPosition().x - block[i]->GetSize().x/2 - ninja->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y + block[i]->GetSize().y/2 == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->SetPosition(ninja->GetPosition().x, ninja->GetPosition().y + ninja->GetSize().y/2);
				ninja->setState(4);
			}
			break;
		case 6:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->GetPosition().x + block[i]->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y + block[i]->GetSize().y/2 + ninja->GetSize().y/2 == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->SetPosition(ninja->GetPosition().x + ninja->GetSize().x/2, ninja->GetPosition().y);
				ninja->setState(5);
			}
			break;
		case 7:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->GetPosition().x + block[i]->GetSize().x/2 + ninja->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y - block[i]->GetSize().y/2 == block[i]->GetPosition().y && typeid(*block[i]) == typeid(StdBlock))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->SetPosition(ninja->GetPosition().x, ninja->GetPosition().y - ninja->GetSize().y/2);
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
			if(player->getPosX() > block[i]->GetPosition().x - (player->getSizeX()/2 + block[i]->GetSize().x/2) && player->getPosX() < block[i]->GetPosition().x + (player->getSizeX()/2 + block[i]->GetSize().x/2) && typeid(*block[i]) == typeid(StdBlock) ) //Kolliderar i x-led
			{
				if(player->getPosY() > block[i]->GetPosition().y - (player->getSizeY()/2 + block[i]->GetSize().y/2) && player->getPosY() < block[i]->GetPosition().y + (player->getSizeY()/2 + block[i]->GetSize().y/2)) //Kolliderar i y-led
				{
					this->collides=true;
					knuffarN=block[i]->GetPosition().x;
				}

			}
		}

		if(collides && player->getPosX() <= knuffarN)
		{
			player->SetPosition(player->GetPosition().x - 1, player->GetPosition().y);
			player->setPosX(player->getPosX() - 1);
		}
		else if(collides && player->getPosX() > knuffarN)
		{
			player->SetPosition(player->GetPosition().x + 1, player->GetPosition().y);
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
			if(player->getPosX() > block[i]->GetPosition().x - (player->getSizeX()/2 + block[i]->GetSize().x/2) && player->getPosX() < block[i]->GetPosition().x + (player->getSizeX()/2 + block[i]->GetSize().x/2) && typeid(*block[i]) == typeid(StdBlock) ) //Kolliderar i x-led
			{
				if(player->getPosY() > block[i]->GetPosition().y - (player->getSizeY()/2 + block[i]->GetSize().y/2) && player->getPosY() < block[i]->GetPosition().y + (player->getSizeY()/2 + block[i]->GetSize().y/2)) //Kolliderar i y-led
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
			if(player->getPosX() > block[i]->GetPosition().x - (player->getSizeX()/2 + block[i]->GetSize().x/2) && player->getPosX() < block[i]->GetPosition().x + (player->getSizeX()/2 + block[i]->GetSize().x/2) && typeid(*block[i]) == typeid(StdBlock) ) //Kolliderar i x-led
			{
				if(player->getPosY() > block[i]->GetPosition().y - (player->getSizeY()/2 + block[i]->GetSize().y/2) && player->getPosY() < block[i]->GetPosition().y + (player->getSizeY()/2 + block[i]->GetSize().y/2)) //Kolliderar i y-led
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
		if(player->getPosY() == block[i]->GetPosition().y - (player->getSizeY()/2 + block[i]->GetSize().y/2) && player->getPosX() > block[i]->GetPosition().x - (player->getSizeX()/2 + block[i]->GetSize().x/2) && player->getPosX() < block[i]->GetPosition().x + (player->getSizeX()/2 + block[i]->GetSize().x/2) && typeid(*block[i]) == typeid(StdBlock))
		{
			collides=true;
		}
	}

	if(!collides)
	{
		if(player->getPreCollides())
			player->setSpeedY(1);
		player->setAccel(1);
		player->setGrounded(false);
		player->setPreCollides(false);
	}
	else
	{
		player->setAccel(0);
		player->setGrounded(true);
		player->setPreCollides(true);
	}

	//Roofcheck
	collides=false;
	for(int i=0;i<nBlocks;i++)
	{
		if(player->getPosY() == block[i]->GetPosition().y + (player->getSizeY()/2 + block[i]->GetSize().y/2) && player->getPosX() > block[i]->GetPosition().x - (player->getSizeX()/2 + block[i]->GetSize().x/2) && player->getPosX() < block[i]->GetPosition().x + (player->getSizeX()/2 + block[i]->GetSize().x/2) && typeid(*block[i]) == typeid(StdBlock))
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
		if(player->getPosX() == block[i]->GetPosition().x - (player->getSizeX()/2 + block[i]->GetSize().x/2) && player->getPosY() > block[i]->GetPosition().y - (player->getSizeY()/2 + block[i]->GetSize().y/2) && player->getPosY() < block[i]->GetPosition().y + (player->getSizeY()/2 + block[i]->GetSize().y/2) && typeid(*block[i]) == typeid(StdBlock))
		{
			wallcollide=true;
			rightwall=true;
		}
		if(player->getPosX() == block[i]->GetPosition().x + (player->getSizeX()/2 + block[i]->GetSize().x/2) && player->getPosY() > block[i]->GetPosition().y - (player->getSizeY()/2 + block[i]->GetSize().y/2) && player->getPosY() < block[i]->GetPosition().y + (player->getSizeY()/2 + block[i]->GetSize().y/2) && typeid(*block[i]) == typeid(StdBlock))
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
	if(p->GetPosition().x == d->GetPosition().x && p->GetPosition().y + (p->GetSize().y/2 - d->GetSize().y/2) == d->GetPosition().y )
	{
		return true;
	}
	return false;
}