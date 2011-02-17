#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	
}

Game::~Game()
{
}

bool Game::init(int level)
{
	//Initiera spel beroende p� levelselect
	mainWnd = new RenderWindow(VideoMode(800, 600, 32), "Ninja'd");
	mainWnd->Show(false);
	mainLvl = new Level(0);
	this->ninjhold = new NinjaHolder(2,0,0);
	collision = new Collision();
	

	temp = 2;
	return false;
}

bool Game::run()
{
	bool running = true;
	mainWnd->Show(true);
	while(running)
	{
		//sf::Sleep(0.2f);
		sf:Sleep(0.01f);
		checkCollision();
		running = update();
		render();
	}
	return false;
}

void Game::cleanUp()
{
	//To delete everything when game closes
	delete mainWnd;
	delete mainLvl;
	delete ninjhold;
}

void Game::checkCollision()
{
	//L�ter kollisionsklass sk�ta detta.
	for(int i=0;i<ninjhold->getNr();i++)
		collision->ninja(mainLvl->getBlocks(),this->ninjhold->getNinjas(i),this->mainLvl->getNr());
}

bool Game::update()
{
	//Update Sensei
	//Update Level
	//Update Ninjas
	Event e;
	while (mainWnd->GetEvent(e))
	{
		//e.Type == Event::MouseMoved;
		// Window closed
		if(e.Type == Event::MouseButtonReleased)
		{
			std::cout << temp << std::endl;
			//ninjas->setState(temp);
			temp++;
			temp%=8;
		}

		if (e.Type == Event::Closed)
		{
			mainWnd->Close();
			return false;
		}
	}
	for(int i=0;i<ninjhold->getNr();i++)
		ninjhold->getNinjas(i)->update();

	return true;
}

void Game::render()
{
	mainWnd->Clear(Color(255, 255, 255));
	mainLvl->render(mainWnd);
	for(int i=0;i<ninjhold->getNr();i++)
		mainWnd->Draw(*ninjhold->getNinjas(i));
	mainWnd->Display();
}
