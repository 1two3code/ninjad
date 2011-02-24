#include "Menu.h"

Menu::Menu()
{
	menuWnd = new RenderWindow(VideoMode(1024, 768, 32), "Ninja'd", Style::Close, WindowSettings());

	background = new Sprite();
	background->SetImage(*ImgHolder::getInst()->background);

	mapPreview = new Sprite();

	mapPreview->SetImage(*ImgHolder::getInst()->maps[0]);
	mapPreview->SetSubRect(IntRect(1,1,17,17));
	mapPreview->SetScale(32,32);
	mapPreview->SetPosition(85, 148);

	btnFrame.x = 640;
	btnFrame.y = 170;
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

	unlocked = 10;
}

Menu::~Menu()
{
	delete menuWnd;
	delete background;
	delete mapPreview;

	for(int i = 0; i < 25; i++)
		delete levelButtons[i];

	delete levelButtons;
}

void Menu::splashScreen()
{
	//Show splashscreen /w Credits + Name
}

int Menu::levelSelect()
{
	menuWnd->Show(true);
	int choice = -25;

	while(choice == -25)
	{		
		sf::Sleep(0.1);
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

	for(int i = 0; i < 25; i ++)
		menuWnd->Draw(*levelButtons[i]);

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
				levelButtons[i]->SetSubRect(IntRect(0,0,72,72));
		}
		
		btn = checkMousePos();
		if(btn > -1 && btn < 25)
		{
			levelButtons[btn]->SetSubRect(IntRect(0,72,72,144));
			if(btn < unlocked)
				mapPreview->SetImage(*ImgHolder::getInst()->maps[btn]);
			else
				mapPreview->SetImage(*ImgHolder::getInst()->locked);
		}

	}
	if(e.Type == Event::MouseButtonReleased)
	{
		btn = checkMousePos();
		if(btn > -1 && btn < unlocked)
			return btn;
		else
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
	else																								//Utanför levelselect, returnera om quit
	{

	}

	return -25;

}





void Menu::Show(bool tf)
{
	menuWnd->Show(tf);
}