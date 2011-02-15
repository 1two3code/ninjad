#include"Collision.h"

Collision::Collision()
{
	collides=true;
}

Collision::~Collision()
{}

int Collision::ninja(Block** block, NinjaIF* ninja, int nBlocks)
{
	this->collides=false;
	ninja->testmove();
	for(int i=0; i<nBlocks && collides==false;i++)
	{
		//cout<<"Block nr "<<i<<": "<<block[i]->GetPosition().x<<" "<<block[i]->GetPosition().y<<" Ninja: "<<ninja->GetPosition().x<<" "<<ninja->GetPosition().y<<" ";
		//cout<<"Nx: "<<ninja->GetPosition().x+ninja->GetSize().x/2<<" Bx: "<<block[i]->GetPosition().x - block[i]->GetSize().x/2<<endl;
		this->collides=true;

		if(ninja->GetPosition().x + ninja->GetSize().x/2 <= block[i]->GetPosition().x - block[i]->GetSize().x/2)//Ninjan är till vänster om blocket
		{collides=false; /*cout<<"L";*/}
		if(ninja->GetPosition().x - ninja->GetSize().x/2 >= block[i]->GetPosition().x + block[i]->GetSize().x/2)//Ninjan är till höger om blocket
			{collides=false; /*cout<<"R";*/}
		if(ninja->GetPosition().y + ninja->GetSize().y/2 <= block[i]->GetPosition().y - block[i]->GetSize().y/2)//Ninjan är ovanför blocket
			{collides=false; /*cout<<"U";*/}
		if(ninja->GetPosition().y - ninja->GetSize().y/2 >= block[i]->GetPosition().y + block[i]->GetSize().y/2)//Ninjan är nedanför blocket
			{collides=false; /*cout<<"D";*/}
		//cout<<endl;
	}
	ninja->retrace();
	//cin.get();
	return collides;
}