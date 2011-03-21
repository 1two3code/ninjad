#ifndef IMGHOLDER_H
#define IMGHOLDER_H
#include <SFML\Graphics.hpp>

using namespace sf;

class ImgHolder
{
private:
	static ImgHolder* pInstance;
	ImgHolder();
	int nMaps;

public:
	Image* background;
	Image* hud;
	Image* buttons;
	Image* arrows;
	Image* blocks;
	Image* blkSpringAct;
	Image* blkFallAct;
	Image* ninRun;
	Image** maps;
	Image* colorCode;
	Image* plyRun;
	Image* plyIdle;
	Image* plyJump;
	Image* pauseScreen;
	Image* icon;
	Image* ninSlide;
	Image* ninFall;
	Image* ninClimb;
	Image* ninArm;
	Image* blockFrame;

	Image* title;
	Image* mousePtr;

	Image* howToPlay;
	Image* levelComplete;

	//Image* menuBackground;
	Image* creditScreen;
	Image* splashScreen;
	Image* pressAnyKey;
	Image* menuButton;
	Image* menuNumbers;
	Image* locked;
	Image* menuhud;
	Image* hand;
	~ImgHolder();
	static ImgHolder* getInst();

	Image* getMaps(int i);
};

#endif