#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	mainWnd = NULL;
	mainLvl = NULL;
	ninjhold = NULL;
	player = NULL;
	background = NULL;
	hud = NULL;
	player = NULL;
	collision = NULL;

}

Game::~Game()
{
	if(mainWnd)
		delete mainWnd;
	if(mainLvl)
		delete mainLvl;
	if(ninjhold)
		delete ninjhold;
	if(player)
		delete player;
	if(background)
		delete background;
	if(hud)
		delete hud;
	//if(player)
		//delete player;
	if(collision)
		delete collision;
	//delete InputHandler::getInstance();
}

bool Game::init(int level)
{
	input = &InputHandler::getInstance();
	mainWnd = new RenderWindow(VideoMode(1024, 768, 32), "Ninja'd", Style::Close, WindowSettings());
	mainWnd->Show(false);

	background = new Sprite();
	background->SetImage(*ImgHolder::getInst()->background);

	hud = new HUDisplay();

	currLevel = level;
	mainLvl = new Level(currLevel);
	this->ninjhold = new NinjaHolder(mainLvl->getNNinjas(), 0, 6, mainLvl->getEntryDoor()); //mainLvl->getNrOfNinjas()
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
		sf::Sleep(0.017f);
		checkCollision();
		running = update();
		render();
	}

	return false;
}

void Game::cleanUp()
{
	//To delete everything when game closes

}

void Game::checkCollision()
{
	//Låter kollisionsklass sköta detta.
	for(int i=0;i<ninjhold->getNr();i++)
		collision->ninja(mainLvl->getBlocks(), ninjhold->getNinjas(i), mainLvl->getNr());

	collision->player(mainLvl->getBlocks(), player, mainLvl->getNr(),mainWnd);
	//cin.get();
}

bool Game::update()
{
	bool run = true;
	Event e;
	
	while (mainWnd->GetEvent(e) && run)
		run = eventHandler(e);				//Flyttade ner hela den här superscoopen till en egen funktion istället. Fresh.

	for(int i=0;i<ninjhold->getNr();i++)
		ninjhold->getNinjas(i)->update();

	player->update(mainWnd);
	player->updateSprite(mainWnd);

	hud->update(mainLvl, player);				//Ska skicka levelID, Ninjor max, ninjor inne, antal block <- levelID osv borde vara ints i main.cpp

	return run;
}

bool Game::eventHandler(Event e)
{
	if(e.Type == Event::MouseButtonPressed)
	{
		if (!(InputHandler::getInstance().getMousePosX(mainWnd) > 96 && InputHandler::getInstance().getMousePosX(mainWnd) < 608 
			&& InputHandler::getInstance().getMousePosY(mainWnd) > 160 && InputHandler::getInstance().getMousePosY(mainWnd) < 672))			//Om musen är inom HUD
		{
			hud->HUDClicked(mainWnd);
		}
	}
	else if(e.Type == Event::MouseButtonReleased)
	{
		if(!(InputHandler::getInstance().getMousePosX(mainWnd) > 96 && InputHandler::getInstance().getMousePosX(mainWnd) < 608 
			&& InputHandler::getInstance().getMousePosY(mainWnd) > 160 && InputHandler::getInstance().getMousePosY(mainWnd) < 672))			//Om musen är inom HUD
		{
			switch(hud->HUDReleased(mainWnd))
			{
			case 0:
				break;
			case 1:
				e.Type = Event::Closed;
				break;
			case 2:
				cout << "Reset..." << endl;
				break;
			case 3:
				cout << "Pause..." << endl;
				break;
			case 4:
				cout << "Sound..." << endl;
				break;
			}	
		}
		else																			//Om musen är inom spelplanen. Sätt ut block ^^
		{
			//float angle;	kan användas om vi ska ha en sprite som pekar där du siktar med musen
			//angle = 57.3065f * atan2(mousePos.y - player->GetPosition().y, mousePos.x - player->GetPosition().x);
			//player->SetRotation(360-angle);

			sf::Vector2f mousePos(input->getMousePosX(mainWnd), input->getMousePosY(mainWnd));
			
			float x = mousePos.x - player->GetPosition().x;
			float y = mousePos.y - player->GetPosition().y; 
			float magnitude = sqrt((x*x)+(y*y));
			x /= magnitude;
			y /= magnitude;


			mainLvl->addBlock(1,player->GetPosition().x+(32*x), player->GetPosition().y+(32*y), 0);
			
		}
	}
	if (e.Type == Event::Closed)
	{
		mainWnd->Close();
		return false;
	}

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
