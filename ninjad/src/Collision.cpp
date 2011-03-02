#include"Collision.h"

Collision::Collision()
{
	collides=true;
	airborne=true;
	savedstate=0;
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
	//1. Står sensei på marken?
	player->setAccel(2);
	player->setGrounded(false);
	for(int i=0; i<nBlocks; i++)
	{
		if(player->GetPosition().y + (player->GetSize().y/2 + block[i]->GetSize().y/2) == block[i]->GetPosition().y && player->GetPosition().x + player->GetSize().x/2 >= block[i]->GetPosition().x - block[i]->GetSize().x/2 && player->GetPosition().x - player->GetSize().x/2 <= block[i]->GetPosition().x + block[i]->GetSize().x/2 && typeid(*block[i]) == typeid(StdBlock))
		{
			player->setAccel(0);
			player->setSpeedY(0);
			player->setGrounded(true);
		}
	}

	//2. Kolliderar sensei med en vägg?
	bool precollides=false;
	player->setHitWall(false);

	this->collides=false;
	for(int i=0; i<nBlocks && collides==false;i++)
	{
		this->collides=true;
		
		if(player->GetPosition().x + player->GetSize().x/2 <= block[i]->GetPosition().x - block[i]->GetSize().x/2)//Ninjan är till vänster om blocket
			collides=false;
		if(player->GetPosition().x - player->GetSize().x/2 >= block[i]->GetPosition().x + block[i]->GetSize().x/2)//Ninjan är till höger om blocket
			collides=false;
		if(player->GetPosition().y + player->GetSize().y/2 <= block[i]->GetPosition().y - block[i]->GetSize().y/2)//Ninjan är ovanför blocket
			collides=false;
		if(player->GetPosition().y - player->GetSize().y/2 >= block[i]->GetPosition().y + block[i]->GetSize().y/2)//Ninjan är nedanför blocket
			collides=false;
		if(typeid(*block[i]) != typeid(StdBlock)) //Blocket är inte ett StdBlock
			collides=false;
	}
	if(collides)
		precollides=true;

	this->collides=false;
	player->testmove(wnd);
	for(int i=0; i<nBlocks && collides==false;i++)
	{
		this->collides=true;
		
		if(player->GetPosition().x + player->GetSize().x/2 <= block[i]->GetPosition().x - block[i]->GetSize().x/2)//Ninjan är till vänster om blocket
			collides=false;
		if(player->GetPosition().x - player->GetSize().x/2 >= block[i]->GetPosition().x + block[i]->GetSize().x/2)//Ninjan är till höger om blocket
			collides=false;
		if(player->GetPosition().y + player->GetSize().y/2 <= block[i]->GetPosition().y - block[i]->GetSize().y/2)//Ninjan är ovanför blocket
			collides=false;
		if(player->GetPosition().y - player->GetSize().y/2 >= block[i]->GetPosition().y + block[i]->GetSize().y/2)//Ninjan är nedanför blocket
			collides=false;
		if(typeid(*block[i]) != typeid(StdBlock)) //Blocket är inte ett StdBlock
			collides=false;
	}
	player->retrace(wnd);
	if(collides && !precollides)
	{
		player->setHitWall(true);
		player->setNextToWall(true);
	}

}