#include"Collision.h"

Collision::Collision()
{
	collides=true;
}

Collision::~Collision()
{}

int Collision::ninja(Block** block, NinjaIF* ninja, int nBlocks)
{
	this->collides=true;
	for(int i=0; i<nBlocks;i++)
	{
		if(ninja->GetPosition().x + ninja->GetSize().x	<	block[i]->GetPosition().x)
			collides=false;
		if(ninja->GetPosition().x	>	block[i]->GetPosition().x + block[i]->GetSize().x)
			collides=false;
		if(ninja->GetPosition().y + ninja->GetSize().y	<	block[i]->GetPosition().y)
			collides=false;
		if(ninja->GetPosition().y	>	block[i]->GetPosition().y + block[i]->GetSize().y)
			collides=false;

		return collides;
	}
}