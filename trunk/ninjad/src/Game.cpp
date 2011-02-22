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
	input = &InputHandler::getInstance();
	//Initiera spel beroende på levelselect
	mainWnd = new RenderWindow(VideoMode(1024, 768, 32), "Ninja'd");
	mainWnd->Show(false);
	background = new Sprite();
	background->SetImage(*ImgHolder::getInst()->background);
	hud = new HUDisplay();
	mainLvl = new Level(0);
	this->ninjhold = new NinjaHolder(20,0,6,mainLvl->getBlocks(),this->mainLvl->getNr());
	player = new Player();
	collision = new Collision();

	return false;
}

bool Game::run()
{
	bool running = true;
	mainWnd->Show(true);
	while(running)
	{
		
		sf::Sleep(0.025f);
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
	delete player;
}

void Game::checkCollision()
{
	//Låter kollisionsklass sköta detta.
	for(int i=0;i<ninjhold->getNr();i++)
		collision->ninja(mainLvl->getBlocks(),this->ninjhold->getNinjas(i),this->mainLvl->getNr());

	collision->player(mainLvl->getBlocks(), this->player, this->mainLvl->getNr(),mainWnd);
	//cin.get();
}

bool Game::update()
{
	//Update HUD
	//Update Sensei
	//Update Level
	//Update Ninjas
	Event e;
	
	while (mainWnd->GetEvent(e))
	{
		//e.Type == Event::MouseMoved;
		// Window closed
		if(e.Type == Event::MouseButtonPressed)
		{
			if (!(InputHandler::getInstance().getMousePosX(mainWnd) > 96 && InputHandler::getInstance().getMousePosX(mainWnd) < 608 
				&& InputHandler::getInstance().getMousePosY(mainWnd) > 160 && InputHandler::getInstance().getMousePosY(mainWnd) < 672))			//Om musen är inom HUD
			{
				hud->HUDClicked(mainWnd);
			}
		}
		if(e.Type == Event::MouseButtonReleased)
		{
			if(!(InputHandler::getInstance().getMousePosX(mainWnd) > 96 && InputHandler::getInstance().getMousePosX(mainWnd) < 608 
				&& InputHandler::getInstance().getMousePosY(mainWnd) > 160 && InputHandler::getInstance().getMousePosY(mainWnd) < 672))			//Om musen är inom HUD
			{
				hud->HUDReleased(mainWnd);

			}
			else																			//Om musen är inom spelplanen. Sätt ut block ^^
			{
				
			}
		}
		
		if (e.Type == Event::Closed)
		{
			mainWnd->Close();
			return false;
		}
	}
	for(int i=0;i<ninjhold->getNr();i++)
		ninjhold->getNinjas(i)->update();
	player->update(mainWnd);
	player->updateSprite(mainWnd);

	hud->update();				//Ska skicka levelID, Ninjor max, ninjor inne, antal block <- levelID osv borde vara ints i main.cpp

	return true;
}

void Game::render()
{

	
	mainWnd->Clear(Color(255, 255, 255));
	mainWnd->Draw(*background);
	hud->render(mainWnd);
	mainLvl->render(mainWnd);
	for(int i=0;i<ninjhold->getNr();i++)
		if(ninjhold->getNinjas(i)->getDrawn()==true)
			mainWnd->Draw(*ninjhold->getNinjas(i));
	mainWnd->Draw(*player);
	mainWnd->Display();
}
