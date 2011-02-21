#include "HUDisplay.h"
#include <iostream>

HUDisplay::HUDisplay()
{
	bz = 72;
	HUDbg = new Sprite();
	HUDbg->SetImage(*ImgHolder::getInst()->hud);

	quitButton = new Sprite();
	quitButton->SetImage(*ImgHolder::getInst()->buttons);
	quitButton->SetSubRect(IntRect(0,0,bz*1,bz));
	quitButton->SetPosition(684, 634);

	resetButton = new Sprite();
	resetButton->SetImage(*ImgHolder::getInst()->buttons);
	resetButton->SetSubRect(IntRect(bz*1,0,bz*2,bz));
	resetButton->SetPosition(684+bz*1, 634);

	pauseButton = new Sprite();
	pauseButton->SetImage(*ImgHolder::getInst()->buttons);
	pauseButton->SetSubRect(IntRect(bz*2,0,bz*3,bz));
	pauseButton->SetPosition(684+bz*2, 634);

	soundButton = new Sprite();
	soundButton->SetImage(*ImgHolder::getInst()->buttons);
	soundButton->SetSubRect(IntRect(bz*3,0,bz*4,bz));
	soundButton->SetPosition(684+bz*3, 634);
	//684, 634
}


HUDisplay::~HUDisplay()
{
	delete HUDbg;
}

void HUDisplay::HUDClicked(RenderWindow* rndwnd)
{
	InputHandler* ip = &InputHandler::getInstance();

	if(ip->getMousePosX(rndwnd) > quitButton->GetPosition().x && ip->getMousePosX(rndwnd) < quitButton->GetPosition().x+quitButton->GetSize().y
		&& ip->getMousePosY(rndwnd) > quitButton->GetPosition().y && ip->getMousePosY(rndwnd) < quitButton->GetPosition().y+quitButton->GetSize().y)
	{
		quitButton->SetSubRect(IntRect(0,bz, bz, bz*2));
	}
	else if(ip->getMousePosX(rndwnd) > resetButton->GetPosition().x && ip->getMousePosX(rndwnd) < resetButton->GetPosition().x+resetButton->GetSize().y
		&& ip->getMousePosY(rndwnd) > resetButton->GetPosition().y && ip->getMousePosY(rndwnd) < resetButton->GetPosition().y+resetButton->GetSize().y)
	{
		resetButton->SetSubRect(IntRect(1*bz,bz, bz*2, bz*2));
	}
	else if(ip->getMousePosX(rndwnd) > pauseButton->GetPosition().x && ip->getMousePosX(rndwnd) < pauseButton->GetPosition().x+pauseButton->GetSize().y
		&& ip->getMousePosY(rndwnd) > pauseButton->GetPosition().y && ip->getMousePosY(rndwnd) < pauseButton->GetPosition().y+pauseButton->GetSize().y)
	{
		pauseButton->SetSubRect(IntRect(2*bz,bz, 3*bz, bz*2));
	}
	else if(ip->getMousePosX(rndwnd) > soundButton->GetPosition().x && ip->getMousePosX(rndwnd) < soundButton->GetPosition().x+soundButton->GetSize().y
		&& ip->getMousePosY(rndwnd) > soundButton->GetPosition().y && ip->getMousePosY(rndwnd) < soundButton->GetPosition().y+soundButton->GetSize().y)
	{
		soundButton->SetSubRect(IntRect(3*bz,bz, 4*bz, bz*2));
	}
}

void HUDisplay::HUDReleased(RenderWindow* rndwnd)
{
	quitButton->SetSubRect(IntRect(0, 0, bz, bz));
	resetButton->SetSubRect(IntRect(1*bz, 0, bz*2, bz));
	pauseButton->SetSubRect(IntRect(2*bz, 0, bz*3, bz));
	soundButton->SetSubRect(IntRect(3*bz, 0, bz*4, bz));

	//Titta om innanför någon av knapparnas trianglar.
	//Hantera händelser somehow
}

void HUDisplay::render(RenderWindow* rndwnd)
{
	rndwnd->Draw(*HUDbg);
	rndwnd->Draw(*quitButton);
	rndwnd->Draw(*resetButton);
	rndwnd->Draw(*pauseButton);
	rndwnd->Draw(*soundButton);
}