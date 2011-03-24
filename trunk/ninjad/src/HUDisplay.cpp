#include "HUDisplay.h"
#include <string>
#include <iostream>

HUDisplay::HUDisplay()
{
	ip = &InputHandler::getInstance();
	clock = new Clock();
	clockMinutes = 0;
	clockSeconds = 0;

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

	speedUpButton = new Sprite();
	speedUpButton->SetImage(*ImgHolder::getInst()->arrows);
	speedUpButton->SetSubRect(IntRect(0,0,62,45));
	speedUpButton->SetPosition(940, 520);

	speedDownButton = new Sprite();
	speedDownButton->SetImage(*ImgHolder::getInst()->arrows);
	speedDownButton->SetSubRect(IntRect(62,0,124,45));
	speedDownButton->SetPosition(940, 565);

	blockFrame = new Sprite();
	blockFrame->SetImage(*ImgHolder::getInst()->blockFrame);
	blockFrame->SetPosition(684+bz*3, 634);

	//684, 634

	font = new Font();
	font->LoadFromFile("./data/misc/ninjadfont.ttf");
	font->SetSmooth(true);
	
	levelText = new String();
	levelText->SetFont(*font);
	levelText->SetPosition(875, 45);
	levelText->SetColor(Color(0, 0, 0));
	levelText->SetSize(50.0f);

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
	jumpBlockText->SetPosition(930, 360);
	jumpBlockText->SetColor(Color(0, 0, 0));

	fallBlockText = new String();
	fallBlockText->SetFont(*font);
	fallBlockText->SetPosition(780,360);
	fallBlockText->SetColor(Color(0, 0, 0));
}


HUDisplay::~HUDisplay()
{
	delete HUDbg;
	delete resetButton;
	delete soundButton;
	delete pauseButton;
	delete quitButton;
	delete speedUpButton;
	delete speedDownButton;
	delete blockFrame;

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

	unsigned short mpx = ip->getMousePosX(rndwnd);
	unsigned short mpy = ip->getMousePosY(rndwnd);

	if(mpx > quitButton->GetPosition().x && mpx < quitButton->GetPosition().x+quitButton->GetSize().y
		&& mpy > quitButton->GetPosition().y && mpy < quitButton->GetPosition().y+quitButton->GetSize().y)
	{
		quitButton->SetSubRect(IntRect(0,bz, bz, bz*2));
	}
	else if(mpx > resetButton->GetPosition().x && mpx < resetButton->GetPosition().x+resetButton->GetSize().y
		&& mpy > resetButton->GetPosition().y && mpy < resetButton->GetPosition().y+resetButton->GetSize().y)
	{
		resetButton->SetSubRect(IntRect(1*bz,bz, bz*2, bz*2));
	}
	else if(mpx > pauseButton->GetPosition().x && mpx < pauseButton->GetPosition().x+pauseButton->GetSize().y
		&& mpy > pauseButton->GetPosition().y && mpy < pauseButton->GetPosition().y+pauseButton->GetSize().y)
	{
		pauseButton->SetSubRect(IntRect(2*bz,bz, 3*bz, bz*2));
	}
	else if(mpx > soundButton->GetPosition().x && mpx < soundButton->GetPosition().x+soundButton->GetSize().y
		&& mpy > soundButton->GetPosition().y && mpy < soundButton->GetPosition().y+soundButton->GetSize().y)
	{
		soundButton->SetSubRect(IntRect(3*bz,bz, 4*bz, bz*2));
	}
	else if(mpx > speedUpButton->GetPosition().x && mpx < speedUpButton->GetPosition().x+speedUpButton->GetSize().y
		&& mpy > speedUpButton->GetPosition().y && mpy < speedUpButton->GetPosition().y+speedUpButton->GetSize().y)
	{
		speedUpButton->SetSubRect(IntRect(0, 45, 62, 90));
	}
	else if(mpx > speedDownButton->GetPosition().x && mpx < speedDownButton->GetPosition().x+speedDownButton->GetSize().y
		&& mpy > speedDownButton->GetPosition().y && mpy < speedDownButton->GetPosition().y+speedDownButton->GetSize().y)
	{
		speedDownButton->SetSubRect(IntRect(62, 45, 124, 90));
	}
}

int HUDisplay::HUDReleased(RenderWindow* rndwnd)
{
	quitButton->SetSubRect(IntRect(0, 0, bz, bz));
	resetButton->SetSubRect(IntRect(1*bz, 0, bz*2, bz));
	pauseButton->SetSubRect(IntRect(2*bz, 0, bz*3, bz));
	soundButton->SetSubRect(IntRect(3*bz, 0, bz*4, bz));
	speedUpButton->SetSubRect(IntRect(0, 0, 62, 45));
	speedDownButton->SetSubRect(IntRect(62,0,124,45));	

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
	else if(mpx > speedUpButton->GetPosition().x && mpx < speedUpButton->GetPosition().x+speedUpButton->GetSize().y
		&& mpy > speedUpButton->GetPosition().y && mpy < speedUpButton->GetPosition().y+speedUpButton->GetSize().y)
	{
		return 5;
	}
	else if(mpx > speedDownButton->GetPosition().x && mpx < speedDownButton->GetPosition().x+speedDownButton->GetSize().y
		&& mpy > speedDownButton->GetPosition().y && mpy < speedDownButton->GetPosition().y+speedDownButton->GetSize().y)
	{
		return 6;
	}

	return 0;
}

void HUDisplay::update(Level* lvl, Player* ply, unsigned short nIn, unsigned short blockSelected)
{
	char temp[8];
	std::string sTemp;

	itoa(lvl->getNLevel()+1, temp, 10);	
	levelText->SetText(temp);
	itoa(nIn, temp, 10);	
	minNinjaText->SetText(temp);
	itoa(lvl->getNNinjas(), temp, 10);	
	maxNinjaText->SetText(temp);

	unsigned short time;
	time = clock->GetElapsedTime();
	clockSeconds = time%60;
	clockMinutes = time/60;
	
	itoa(clockMinutes, &temp[0], 10);
	sTemp = temp;
	sTemp += ":";
	itoa(clockSeconds, &temp[0], 10);
	sTemp += temp;
	timeText->SetText(sTemp);


	itoa(lvl->getNPBlocks(), temp, 10);
	playerBlockText->SetText(temp);
	itoa(lvl->getNJBlocks(), temp, 10);
	springBlockText->SetText(temp);
	itoa(lvl->getNSBlocks(), temp, 10);
	jumpBlockText->SetText(temp);
	itoa(lvl->getNFBlocks(), temp, 10);
	fallBlockText->SetText(temp);


	moveBlockFrame(blockSelected);

}

void HUDisplay::render(RenderWindow* rndwnd)
{

	rndwnd->Draw(*blockFrame);
	rndwnd->Draw(*HUDbg);
	rndwnd->Draw(*quitButton);
	rndwnd->Draw(*resetButton);
	rndwnd->Draw(*pauseButton);
	rndwnd->Draw(*soundButton);
	rndwnd->Draw(*speedUpButton);
	rndwnd->Draw(*speedDownButton);

	rndwnd->Draw(*levelText);
	rndwnd->Draw(*minNinjaText);
	rndwnd->Draw(*maxNinjaText);
	rndwnd->Draw(*timeText);
	rndwnd->Draw(*playerBlockText);
	rndwnd->Draw(*springBlockText);
	rndwnd->Draw(*fallBlockText);
	rndwnd->Draw(*jumpBlockText);	
}


void HUDisplay::moveBlockFrame(unsigned short type)
{
	switch(type)
	{
	default:
		blockFrame->SetPosition(660, 220);
		break;
	case 4:
		blockFrame->SetPosition(810, 310);
		break;
	case 5:
		blockFrame->SetPosition(810, 220);
		break;
	case 6:
		blockFrame->SetPosition(660, 310);
		break;
	case 7:
		blockFrame->SetPosition(660, 220);
		break;
	}

}