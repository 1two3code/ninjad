#include "HUDisplay.h"
#include <iostream>

HUDisplay::HUDisplay()
{
	ip = &InputHandler::getInstance();
	clk = new Clock();
	bz = 72;

	HUDbg = new Sprite();
	HUDbg->SetImage(*ImgHolder::getInst()->hud);


	resetButton = new Sprite();
	resetButton->SetImage(*ImgHolder::getInst()->buttons);
	resetButton->SetSubRect(IntRect(bz*1,0,bz*2,bz));
	resetButton->SetPosition(684, 634);
	//resetButton->SetScale(2,2);
	
	soundButton = new Sprite();
	soundButton->SetImage(*ImgHolder::getInst()->buttons);
	soundButton->SetSubRect(IntRect(bz*3,0,bz*4,bz));
	soundButton->SetPosition(684+bz*1, 634);

	pauseButton = new Sprite();
	pauseButton->SetImage(*ImgHolder::getInst()->buttons);
	pauseButton->SetSubRect(IntRect(bz*2,0,bz*3,bz));
	pauseButton->SetPosition(684+bz*2, 634);

	quitButton = new Sprite();
	quitButton->SetImage(*ImgHolder::getInst()->buttons);
	quitButton->SetSubRect(IntRect(0,0,bz*1,bz));
	quitButton->SetPosition(684+bz*3, 634);

	//684, 634

	font = new Font();
	font->LoadFromFile("data/JustTheWayYouAre.ttf");
	
	levelText = new String();
	levelText->SetFont(*font);
	levelText->SetPosition(875, 40);
	levelText->SetColor(Color(0, 0, 0));
	levelText->SetSize(64.0f);

	minNinjaText = new String();
	minNinjaText->SetFont(*font);
	minNinjaText->SetPosition(150, 690);
	minNinjaText->SetColor(Color(0, 0, 0));

	maxNinjaText = new String();
	maxNinjaText->SetFont(*font);
	maxNinjaText->SetPosition(220, 690);
	maxNinjaText->SetColor(Color(0, 0, 0));

	timeText = new String();
	timeText->SetFont(*font);
	timeText->SetPosition(470, 690);
	timeText->SetColor(Color(0, 0, 0));

	playerBlockText = new String();
	playerBlockText->SetFont(*font);
	playerBlockText->SetPosition(780, 260);
	playerBlockText->SetColor(Color(0, 0, 0));

	springBlockText = new String();
	springBlockText->SetFont(*font);
	springBlockText->SetPosition(930,260);
	springBlockText->SetColor(Color(0, 0, 0));

	jumpBlockText = new String();
	jumpBlockText->SetFont(*font);
	jumpBlockText->SetPosition(780, 360);
	jumpBlockText->SetColor(Color(0, 0, 0));

	fallBlockText = new String();
	fallBlockText->SetFont(*font);
	fallBlockText->SetPosition(930,360);
	fallBlockText->SetColor(Color(0, 0, 0));
}


HUDisplay::~HUDisplay()
{
	delete HUDbg;
	delete font;
	delete levelText;
	delete maxNinjaText;
	delete minNinjaText;
	delete timeText;
	delete playerBlockText;
	delete jumpBlockText;
	delete springBlockText;
	delete fallBlockText;
}

void HUDisplay::HUDClicked(RenderWindow* rndwnd)
{

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

int HUDisplay::HUDReleased(RenderWindow* rndwnd)
{
	quitButton->SetSubRect(IntRect(0, 0, bz, bz));
	resetButton->SetSubRect(IntRect(1*bz, 0, bz*2, bz));
	pauseButton->SetSubRect(IntRect(2*bz, 0, bz*3, bz));
	soundButton->SetSubRect(IntRect(3*bz, 0, bz*4, bz));

	unsigned short mpx = ip->getMousePosX(rndwnd);
	unsigned short mpy = ip->getMousePosY(rndwnd);

	if(mpx > quitButton->GetPosition().x && mpx < quitButton->GetPosition().x+quitButton->GetSize().y
		&& mpy > quitButton->GetPosition().y && mpy < quitButton->GetPosition().y+quitButton->GetSize().y)
	{
		return 1;
	}
	else if(mpx > resetButton->GetPosition().x && mpx < resetButton->GetPosition().x+resetButton->GetSize().y
		&& mpy > resetButton->GetPosition().y && mpy < resetButton->GetPosition().y+resetButton->GetSize().y)
	{
		return 2;
	}
	else if(mpx > pauseButton->GetPosition().x && mpx < pauseButton->GetPosition().x+pauseButton->GetSize().y
		&& mpy > pauseButton->GetPosition().y && mpy < pauseButton->GetPosition().y+pauseButton->GetSize().y)
	{		
		return 3;
	}
	else if(mpx > soundButton->GetPosition().x && mpx < soundButton->GetPosition().x+soundButton->GetSize().y
		&& mpy > soundButton->GetPosition().y && mpy < soundButton->GetPosition().y+soundButton->GetSize().y)
	{
		return 4;
	}

	return 0;
}

void HUDisplay::update(Level* lvl, Player* ply)
{
	char temp[5];

	itoa(lvl->getNLevel(), temp, 10);	
	levelText->SetText(temp);
	itoa(0, temp, 10);	
	minNinjaText->SetText(temp);
	itoa(lvl->getNNinjas(), temp, 10);	
	maxNinjaText->SetText(temp);

	itoa((int)clk->GetElapsedTime(), temp, 10);	
	timeText->SetText(temp);


	itoa(lvl->getNPBlocks(), temp, 10);
	playerBlockText->SetText(temp);
	itoa(lvl->getNJBlocks(), temp, 10);
	springBlockText->SetText(temp);
	itoa(lvl->getNSBlocks(), temp, 10);
	jumpBlockText->SetText(temp);
	itoa(lvl->getNFBlocks(), temp, 10);
	fallBlockText->SetText(temp);
}

void HUDisplay::render(RenderWindow* rndwnd)
{
	rndwnd->Draw(*HUDbg);
	rndwnd->Draw(*quitButton);
	rndwnd->Draw(*resetButton);
	rndwnd->Draw(*pauseButton);
	rndwnd->Draw(*soundButton);

	rndwnd->Draw(*levelText);
	rndwnd->Draw(*minNinjaText);
	rndwnd->Draw(*maxNinjaText);
	rndwnd->Draw(*timeText);
	rndwnd->Draw(*playerBlockText);
	rndwnd->Draw(*springBlockText);
	rndwnd->Draw(*fallBlockText);
	rndwnd->Draw(*jumpBlockText);

}