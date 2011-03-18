#include "Menu.h"

Menu::Menu()
{
	menuWnd = new RenderWindow(VideoMode(1024, 768, 32), "Ninja'd", Style::Close, WindowSettings());
	//menuWnd->UseVerticalSync(true);
	menuWnd->SetFramerateLimit(30);
	menuWnd->SetIcon(16, 16, ImgHolder::getInst()->icon->GetPixelsPtr());

	background = new Sprite();
	background->SetImage(*ImgHolder::getInst()->background);

	mapPreview = new Sprite();

	mapPreview->SetImage(*ImgHolder::getInst()->maps[0]);
	mapPreview->SetSubRect(IntRect(1,1,17,17));
	mapPreview->SetScale(32,32);
	mapPreview->SetPosition(85, 148);

	btnFrame.x = 640;
	btnFrame.y = 170;

	numbers = new Sprite();
	numbers->SetImage(*ImgHolder::getInst()->menuNumbers);
	numbers->SetPosition(btnFrame.x, btnFrame.y);

	quitButton = new Sprite();
	quitButton->SetImage(*ImgHolder::getInst()->buttons);
	quitButton->SetSubRect(IntRect(0, 0, 72, 72));
	quitButton->SetPosition(684+72*3, 634);

	htpButton = new Sprite();
	htpButton->SetImage(*ImgHolder::getInst()->buttons);
	htpButton->SetSubRect(IntRect(288, 0, 360, 72));
	htpButton->SetPosition(684+72*2, 634);

	credButton = new Sprite();
	credButton->SetImage(*ImgHolder::getInst()->buttons);
	credButton->SetSubRect(IntRect(360, 0, 432, 72));
	credButton->SetPosition(684+72, 634);

	menuHUD = new Sprite;
	menuHUD->SetImage(*ImgHolder::getInst()->menuhud);
	menuHUD->SetPosition(0, 0);


	nNinjas  = new String();
	//nNinjas->SetSize(
	nNinjas->SetPosition(120,700); 
	nStd = new String();
	nStd->SetPosition(2*120,700); 
	nFall = new String();
	nFall->SetPosition(3*120,700); 
	nJump = new String();
	nJump->SetPosition(4*120,700); 
	nSpring = new String();
	nSpring->SetPosition(5*120,700); 

	howToPlayScreen = new Sprite();
	howToPlayScreen->SetImage(*ImgHolder::getInst()->howToPlay);
	howToPlayScreen->SetPosition(0, 0);
	howToPlay = false;

	credScreen = new Sprite();
	credScreen->SetImage(*ImgHolder::getInst()->creditScreen);
	credScreen->SetPosition(0, 0);
	credits = false;


	levelButtons = new Sprite*[25];
	Sprite* temp;

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			levelButtons[j + i*5] = new Sprite();
			temp = levelButtons[j + i*5];			
			temp->SetImage(*ImgHolder::getInst()->menuButton);
			temp->SetSubRect(IntRect(0, 0, 72, 72));
			temp->SetPosition(btnFrame.x + j*temp->GetSize().x, btnFrame.y + i*temp->GetSize().y);
		}
	}

	buttonPointed = -1;
	buttonClicked = -1;
	unlocked = 10;
}

Menu::~Menu()
{
	delete menuWnd;
	delete background;
	delete mapPreview;
	delete numbers;
	delete quitButton;
	delete htpButton;
	delete howToPlayScreen;
	delete credButton;
	delete credScreen;
	delete menuHUD;
	delete nNinjas;
	delete nStd;
	delete nFall;
	delete nSpring;
	delete nJump;

	for(int i = 0; i < 25; i++)
		delete levelButtons[i];

	delete [] levelButtons;
}


int Menu::levelSelect()
{
	menuWnd->Show(true);
	int choice = -25;

	while(choice == -25)
	{		
		choice = update();
		render();		
	}
	return choice;
}

int Menu::update()
{
	int choice = -25;
	bool eBool = true;
	Event e;

	while(menuWnd->GetEvent(e) && choice == -25)
		choice = eventHandler(e);

	return choice;
}

void Menu::render()
{
	menuWnd->Clear(Color(0,0,0));
	
	menuWnd->Draw(*background);	
	menuWnd->Draw(*mapPreview);
	menuWnd->Draw(*menuHUD);
	menuWnd->Draw(*nNinjas);
	menuWnd->Draw(*nStd);
	menuWnd->Draw(*nFall);
	menuWnd->Draw(*nJump);
	menuWnd->Draw(*nSpring);

	for(int i = 0; i < 25; i ++)
		menuWnd->Draw(*levelButtons[i]);

	menuWnd->Draw(*numbers);
	if(howToPlay)
		menuWnd->Draw(*howToPlayScreen);
	else if(credits)
		menuWnd->Draw(*credScreen);

	menuWnd->Draw(*quitButton);
	menuWnd->Draw(*htpButton);
	menuWnd->Draw(*credButton);

	menuWnd->Display();
}

int Menu::eventHandler(Event e)
{
	int btn = -25;
	if(e.Type == Event::MouseMoved)
	{
		for(int i = 0; i < 25; i++)
		{
			if(levelButtons[i]->GetSubRect().Top > 0)				//L,T,R,B
			{
				levelButtons[i]->SetSubRect(IntRect(0,0,72,72));
				i = 25;				//Break early since only one button can be targeted at once.
			}
		}
		
		btn = checkMousePos();
		if(btn > -1 && btn < 25)
		{			
			if(btn != buttonClicked)
				levelButtons[btn]->SetSubRect(IntRect(0,72,72,144));
			else
				levelButtons[btn]->SetSubRect(IntRect(0, 144, 72, 216));
			if(btn < unlocked)
			{
				map = ImgHolder::getInst()->maps[btn];
				mapPreview->SetImage(*map);
				changeText(true);
			}
			else
			{
				mapPreview->SetImage(*ImgHolder::getInst()->locked);
				changeText(false);
			}
		}

	}
	if(e.Type == Event::MouseButtonPressed)
	{
		int temp = checkMousePos();
		if(temp == -1)
		{
			quitButton->SetSubRect(IntRect(0, 72, 72, 144));
			SndHolder::getInst()->sndClick.Play();//sndClick->Play();
		}
		else if(temp > -1 && temp < unlocked)
		{
			levelButtons[temp]->SetSubRect(IntRect(0, 144, 72, 216));
			buttonClicked = temp;
			SndHolder::getInst()->sndClick.Play();
		}
		else if(temp == -2)
		{
			htpButton->SetSubRect(IntRect(288, 72, 360, 144));
			SndHolder::getInst()->sndClick.Play();
		}
		else if(temp == -3)
		{
			credButton->SetSubRect(IntRect(360, 72, 432, 144));
			SndHolder::getInst()->sndClick.Play();
		}
	}
	if(e.Type == Event::MouseButtonReleased)
	{
		btn = checkMousePos();
		if(btn > -1 && btn < unlocked && btn == buttonClicked)
			return btn;
		else if(btn == -3)
			credits = switchBool(credits);
		else if(btn == -2)
			howToPlay = switchBool(howToPlay);
		else if(btn == -1)
			return -1;
	
		quitButton->SetSubRect(IntRect(0, 0, 72, 72));
		htpButton->SetSubRect(IntRect(288, 0, 360, 72));
		credButton->SetSubRect(IntRect(360, 0, 432, 72));
		buttonClicked = -1;	
		return -25;
		
	}
	if(e.Type == Event::Closed)
		return -1;

	return -25;
}

int Menu::checkMousePos()
{
	int mpx = input->getMousePosX(menuWnd);
	int mpy = input->getMousePosY(menuWnd);

	if(mpx > btnFrame.x && mpx < btnFrame.x+72*5 && mpy > btnFrame.y && mpy < btnFrame.y+72*5)		//inom Level-select området Return vilken knapp den är på.
	{
		mpx -= btnFrame.x;
		mpy -= btnFrame.y;
		mpx /= 72;
		mpy /= 72;
		
		return mpy*5 + mpx;
	}
	else if(mpx > quitButton->GetPosition().x && mpx < quitButton->GetPosition().x+quitButton->GetSize().y
		&& mpy > quitButton->GetPosition().y && mpy < quitButton->GetPosition().y+quitButton->GetSize().y)
	{
		return -1;	

	}
	else if(mpx > htpButton->GetPosition().x && mpx < htpButton->GetPosition().x+htpButton->GetSize().y
		&& mpy > htpButton->GetPosition().y && mpy < htpButton->GetPosition().y+htpButton->GetSize().y)
	{
		return -2;	
	}
	else if(mpx > credButton->GetPosition().x && mpx < credButton->GetPosition().x+credButton->GetSize().y
		&& mpy > credButton->GetPosition().y && mpy < credButton->GetPosition().y+credButton->GetSize().y)
	{
		return -3;
	}

	return -25;

}

void Menu::Show(bool tf)
{
	menuWnd->Show(tf);
}

void Menu::splashScreen()
{
	//Skulle kunna ha en video uppspelad här som splash-screen om man pallar, tills vidare tycker jag bara vi kör med en bild med Credits samt "press any key"
	//ev. ha någonting litet animerat aono

	bool splash = true;
	Event e;

	Sprite splashScreen;
	splashScreen.SetImage(*ImgHolder::getInst()->splashScreen);
	String str;
	str.SetText("Press any key to continue");
	
	str.SetColor(Color(0,0,0));
	str.SetPosition(450, 420);
	
	while(splash)
	{
		menuWnd->Draw(splashScreen);
		menuWnd->Draw(str);
		menuWnd->Display();
		while(menuWnd->GetEvent(e))
		{
			if(e.Type == Event::KeyPressed )
				splash = false;
		}
	}
}


bool Menu::switchBool(bool tf)
{
	if(tf)
		return false;
	else
		return true;
}

void Menu::changeText(bool preview)
{
	if(preview)
	{
		char temp[8];
		itoa(map->GetPixel(0,18).r, temp, 10);	
		nNinjas->SetText(temp);

		itoa(map->GetPixel(1,18).r, temp, 10);	
		nStd->SetText(temp);

		itoa(map->GetPixel(2,18).r, temp, 10);	
		nFall->SetText(temp);

		itoa(map->GetPixel(3,18).r, temp, 10);	
		nJump->SetText(temp);

		itoa(map->GetPixel(4,18).r, temp, 10);	
		nSpring->SetText(temp);
	}
	else
	{
		nNinjas->SetText("X");
		nStd->SetText("X");
		nFall->SetText("X");
		nJump->SetText("X");
		nSpring->SetText("X");
	}

}

void Menu::setUnlockedLevels(unsigned short levels)
{
	unlocked = levels;
}