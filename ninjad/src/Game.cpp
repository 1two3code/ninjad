#include "Game.h"

Game::Game()
{
	
}

Game::~Game()
{
}

bool Game::init(int level)
{
	ninja = new Sprite();
	ninja->SetImage(*ImgHolder::getInst()->ninja);
	ninja->SetSubRect(IntRect(0,0,16,16));
	ninja->SetPosition(32,32);
	ninja->FlipX(true);
	ninja->FlipY(true);
	ninjago = false;
	frame = 0;

	//Initiera spel beroende på levelselect
	mainWnd = new RenderWindow(VideoMode(800, 600, 32), "Ninja'd");
	mainWnd->Show(false);
	mainLvl = new Level(2);
	
	return false;
}

bool Game::run()
{
	bool running = true;
	mainWnd->Show(true);
	while(running)
	{
		running = update();
		render();
	}
	return false;
}

void Game::cleanUp()
{
	//To delete everything when game closes
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
			if(ninjago)
				ninjago = false;
			else
				ninjago = true;
		}

		if (e.Type == Event::Closed)
		{
			mainWnd->Close();
			return false;
		}
	}
	updNinja();
	return true;
}

void Game::render()
{
	mainWnd->Clear(Color(255, 255, 255));
	mainLvl->render(mainWnd);
	mainWnd->Draw(*ninja);
	mainWnd->Display();
}

void Game::updNinja()
{
	if(ninjago)
	{
		ninja->SetSubRect(IntRect(frame*16,0,frame*16+15,15));
		ninja->Move(3, 0);

		frame++;
		frame %= 4;
	}
}