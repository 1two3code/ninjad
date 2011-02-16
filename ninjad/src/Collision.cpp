#include"Collision.h"

Collision::Collision()
{
	collides=true;
}

Collision::~Collision()
{}

void Collision::ninja(Block** block, NinjaIF* ninja, int nBlocks)
{

	//1. Har blocket under fötterna försvunnit?

	//2. Krock med vägg
	this->collides=false;
	ninja->testmove();
	for(int i=0; i<nBlocks && collides==false;i++)
	{
		this->collides=true;

		//cout<<"Block "<<i<<" X: "<<block[i]->GetPosition().x<<" Y: "<<block[i]->GetPosition().y<<" Ninja X: "<<ninja->GetPosition().x<<" Y: "<<ninja->GetPosition().y<<endl;
		
		if(ninja->GetPosition().x + ninja->GetSize().x/2 <= block[i]->GetPosition().x - block[i]->GetSize().x/2)//Ninjan är till vänster om blocket
			collides=false;
		if(ninja->GetPosition().x - ninja->GetSize().x/2 >= block[i]->GetPosition().x + block[i]->GetSize().x/2)//Ninjan är till höger om blocket
			collides=false;
		if(ninja->GetPosition().y + ninja->GetSize().y/2 <= block[i]->GetPosition().y - block[i]->GetSize().y/2)//Ninjan är ovanför blocket
			collides=false;
		if(ninja->GetPosition().y - ninja->GetSize().y/2 >= block[i]->GetPosition().y + block[i]->GetSize().y/2)//Ninjan är nedanför blocket
			collides=false;
	}
	ninja->retrace();
	if(collides)
		ninjaHitsWall(ninja);

	//3. Gå över en kant
	if((((int)(ninja->GetPosition().x)%(int)(block[0]->GetSize().x) == 0) && ((int)ninja->getState()%2 == 0)) || (((int)(ninja->GetPosition().y)%(int)(block[0]->GetSize().y) == 0) && ((int)ninja->getState()%2 == 1)))
	{
		this->foothold=false;
		switch(ninja->getState())
		{
		case 0:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->GetPosition().x - block[i]->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y + block[i]->GetSize().y/2 + ninja->GetSize().y/2 == block[i]->GetPosition().y)
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
				if(ninja->GetPosition().x + block[i]->GetSize().x/2 + ninja->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y + block[i]->GetSize().y/2 == block[i]->GetPosition().y)
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
				if(ninja->GetPosition().x + block[i]->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y - block[i]->GetSize().y/2 - ninja->GetSize().y/2 == block[i]->GetPosition().y)
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
				if(ninja->GetPosition().x - block[i]->GetSize().x/2 - ninja->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y - block[i]->GetSize().y/2 == block[i]->GetPosition().y)
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
				if(ninja->GetPosition().x - block[i]->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y - block[i]->GetSize().y/2 - ninja->GetSize().y/2 == block[i]->GetPosition().y)
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
				if(ninja->GetPosition().x - block[i]->GetSize().x/2 - ninja->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y + block[i]->GetSize().y/2 == block[i]->GetPosition().y)
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
				if(ninja->GetPosition().x + block[i]->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y + block[i]->GetSize().y/2 + ninja->GetSize().y/2 == block[i]->GetPosition().y)
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
				if(ninja->GetPosition().x + block[i]->GetSize().x/2 + ninja->GetSize().x/2 == block[i]->GetPosition().x && ninja->GetPosition().y - block[i]->GetSize().y/2 == block[i]->GetPosition().y)
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
	//cin.get();
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