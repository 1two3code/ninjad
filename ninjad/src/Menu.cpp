#include "Menu.h"

Menu::Menu()
{
	menuWnd = new RenderWindow(VideoMode(1024, 768, 32), "Ninja'd", Style::Close, WindowSettings());
	//menuWnd->UseVerticalSync(true);
	menuWnd->ShowMouseCursor(false);
	menuWnd->SetFramerateLimit(30);
	menuWnd->SetIcon(16, 16, ImgHolder::getInst()->icon->GetPixelsPtr());

	background = new Sprite();
	background->SetImage(*ImgHolder::getInst()->background);

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
	menuHUD->SetPosition(110, 682);

	font = new Font();
	font->LoadFromFile("./data/misc/ninjadfont.ttf");
	font->SetSmooth(true);

	nNinjas  = new String();
	nNinjas->SetFont(*font);
	nNinjas->SetColor(Color(0,0,0));
	nNinjas->SetSize(22);
	nNinjas->SetPosition(190,680);

	nNinjReq  = new String();
	nNinjReq->SetFont(*font);
	nNinjReq->SetColor(Color(0,0,0));
	nNinjReq->SetSize(22);
	nNinjReq->SetPosition(220,695);

	nStd = new String();
	nStd->SetPosition(290,682);
	nStd->SetFont(*font);
	nStd->SetColor(Color(0,0,0));
	nStd->SetSize(20);

	nFall = new String();
	nFall->SetPosition(290,709); 
	nFall->SetFont(*font);
	nFall->SetColor(Color(0,0,0));
	nFall->SetSize(20);

	nJump = new String();
	nJump->SetPosition(375,682);
	nJump->SetFont(*font);
	nJump->SetColor(Color(0,0,0));
	nJump->SetSize(20);

	nSpring = new String();
	nSpring->SetPosition(375,709);
	nSpring->SetFont(*font);
	nSpring->SetColor(Color(0,0,0));
	nSpring->SetSize(20);

	howToPlayScreen = new Sprite();
	howToPlayScreen->SetImage(*ImgHolder::getInst()->howToPlay);
	howToPlayScreen->SetPosition(0, 0);
	howToPlay = false;

	credScreen = new Sprite();
	credScreen->SetImage(*ImgHolder::getInst()->creditScreen);
	credScreen->SetPosition(0, 0);
	credits = false;

	mptr = new Sprite();
	mptr->SetImage(*ImgHolder::getInst()->mousePtr);
	mptr->SetCenter(0,0);
	mptr->SetPosition(0,0);

	locked = new Sprite();
	locked->SetImage(*ImgHolder::getInst()->locked);
	locked->SetPosition(64+32, 128+32);


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

	previewArray =  new Sprite*[324];
	for(int i = 0; i < 324; i++)
	{
		previewArray[i] = NULL;
	}
	//delete temp;
	isLocked = true;
}

Menu::~Menu()
{
	delete menuWnd;
	delete background;
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
	delete mptr;
	delete font;
	delete nNinjReq;
	delete locked;

	for(int i = 0; i < 25; i++)
		delete levelButtons[i];

	delete [] levelButtons;

	for(int i = 0; i < 324; i++)
	{
		if(previewArray[i] != NULL)
			delete previewArray[i];
	}
	delete [] previewArray;
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

	while(menuWnd->GetEvent(e) && choice == -25){
		choice = eventHandler(e);
		if(e.Type == Event::MouseMoved)
			mptr->SetPosition(e.MouseMove.X, e.MouseMove.Y);
	}
	return choice;
}

void Menu::render()
{
	menuWnd->Clear(Color(0,0,0));
	
	menuWnd->Draw(*background);	

	menuWnd->Draw(*menuHUD);
	menuWnd->Draw(*nNinjas);
	menuWnd->Draw(*nStd);
	menuWnd->Draw(*nFall);
	menuWnd->Draw(*nJump);
	menuWnd->Draw(*nSpring);
	menuWnd->Draw(*nNinjReq);

	for(int i = 0; i < 25; i ++)
		menuWnd->Draw(*levelButtons[i]);

	for(int i = 0; i < 324; i++)
	{
		if(previewArray != NULL)
		{
			if(previewArray[i] != NULL)
				menuWnd->Draw(*previewArray[i]);
		}
	}

	if(isLocked)
		menuWnd->Draw(*locked);



	menuWnd->Draw(*numbers);
	menuWnd->Draw(*quitButton);

	if(!howToPlay) menuWnd->Draw(*htpButton);
	if(!credits)   menuWnd->Draw(*credButton);

	if(howToPlay)
	{
		menuWnd->Draw(*howToPlayScreen);
		menuWnd->Draw(*htpButton);
	}
	else if(credits)
	{
		menuWnd->Draw(*credScreen);
		menuWnd->Draw(*credButton);
	}

	menuWnd->Draw(*mptr);
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

			if(btn >= unlocked)
				isLocked = true;

			else
				isLocked = false;
			map = ImgHolder::getInst()->maps[btn];
			changePreview(btn);
			changeText(true);

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

	Animation* pressAnyKey = new Animation(ImgHolder::getInst()->pressAnyKey, 2, 600, 200, 15, true, true);
	pressAnyKey->sprite.SetCenter(300, 100);
	pressAnyKey->sprite.SetPosition(512, 500);
	pressAnyKey->sprite.SetScale(0.5f, 0.5f);
	Sprite title;
	title.SetImage(*ImgHolder::getInst()->title);
	title.SetCenter(640, 320);
	title.SetPosition(512, 300);
	float titleScale = 2.0f;
	title.SetScale(titleScale, titleScale);
	float maxtitleScale = 0.3f;
	float mintitleScale = 0.25f;
	float titleScaleSpeed = -0.01f;
	float maxTitleRot = 10.0f;
	float minTitleRot = -10.0f;
	float titleRotSpeed = 2.0f;
	float currentRot = 0.0f;

	bool introDone = false;

	splashScreen.SetImage(*ImgHolder::getInst()->splashScreen);

	SndHolder::getInst()->musIntro.Play();

	SndHolder::getInst()->musTheme.SetLoop(true);

	
	while(splash)
	{
		title.Rotate(titleRotSpeed);
		currentRot = title.GetRotation();
		if(currentRot > 180)
			currentRot = currentRot - 360;
		if(currentRot > maxTitleRot) titleRotSpeed = -0.5f;
		if(currentRot < minTitleRot) titleRotSpeed = 0.5f;
		title.SetScale(title.GetScale().x + titleScaleSpeed, title.GetScale().y + titleScaleSpeed);
		if(title.GetScale().x > maxtitleScale && titleScaleSpeed == 0.01f) titleScaleSpeed = -0.01f;
		if(title.GetScale().x < mintitleScale)
		{
			titleScaleSpeed = 0.01f;
		}
		pressAnyKey->Update();
		if(SndHolder::getInst()->musIntro.GetStatus() == Sound::Status::Stopped && !introDone)
		{
			SndHolder::getInst()->musTheme.Play();
			introDone = true;
		}
		menuWnd->Draw(splashScreen);

		if(introDone) menuWnd->Draw(pressAnyKey->sprite);
		menuWnd->Draw(title);
		menuWnd->Display();
		while(menuWnd->GetEvent(e))
		{
			if(e.Type == Event::KeyPressed && introDone)
				splash = false;
		}
	}
		delete pressAnyKey;

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

		itoa(map->GetPixel(5,18).r, temp, 10);	
		nNinjReq->SetText(temp);

	}
	else
	{
		nNinjas->SetText("");
		nStd->SetText("");
		nFall->SetText("");
		nJump->SetText("");
		nSpring->SetText("");
		nNinjReq->SetText("");
	}

}

void Menu::setUnlockedLevels(unsigned short levels)
{
	unlocked = levels;
}


int Menu::findType(Color col)
{
	Image* code = ImgHolder::getInst()->colorCode;	

	for(int i = 0; i < 12; i++)
	{
		if(col.r == code->GetPixel(i, 0).r && col.g == code->GetPixel(i, 0).g && col.b == code->GetPixel(i, 0).b)
		{
			return i;
		}
	}

	return 0;
}

Sprite* Menu::createSprite(int type)
{
	Sprite* rtn = NULL;
	if(type > 0)
	{
		rtn = new Sprite();
		rtn->SetImage(*ImgHolder::getInst()->blocks);
		switch(type)
		{
		case 1:
			rtn->SetSubRect(IntRect(7*32, 0, 7*32+32, 32));
			break;
		case 2:
			rtn->SetSubRect(IntRect(type*32, 0, type*32+32, 32));
			break;
		case 3:
			rtn->SetSubRect(IntRect(type*32, 0, type*32+32, 32));
			break;
		case 4:
			rtn->SetSubRect(IntRect(6*32, 0, 6*32+32, 32));
			break;
		case 5:
			rtn->SetSubRect(IntRect(type*32, 0, type*32+32, 32));
			break;
		case 6:
			rtn->SetSubRect(IntRect(4*32, 0, 4*32+32, 32));
			break;
		case 7:
			rtn->SetSubRect(IntRect(1*32, 0, 1*32+32, 32));
			break;
		case 8:
			rtn->SetSubRect(IntRect(type*32, 0, type*32+32, 32));
			break;

		}
	}	

	return rtn;
}

void Menu::changePreview(unsigned short u)
{
	for(int i = 0; i < 324; i++)
	{
		if(previewArray != NULL)
		{
			if(previewArray[i] != NULL)
			{
				delete previewArray[i];
				previewArray[i] = NULL;
			}
		}
	}

	int w = map->GetWidth();
	int h = map->GetHeight()-1;
	int type = 0;
	int n = 0;
	Sprite* temp = NULL;

	for(int i = 1; i < w-1; i++)
	{
		for(int j = 1; j < h-1; j++)
		{

			type =  findType(map->GetPixel(i,j));
			temp = createSprite(type);
			if(temp != NULL)
			{

				previewArray[n] = temp;
				previewArray[n]->SetPosition(64+i*32.0f, 128+j*32.0f);
				n++;
				temp = NULL;
			}

		}

	}
	delete temp;
}
