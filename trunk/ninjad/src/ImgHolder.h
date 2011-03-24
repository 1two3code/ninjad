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
	Image* blkTrapIdle;
	Image* ninRun;
	Image* ninSlide;
	Image* ninFall;
	Image* ninClimb;
	Image* ninDeath;
	Image* ninArm;
	Image* colorCode;
	Image* plyRun;
	Image* plyIdle;
	Image* plyJump;
	Image* hand;
	Image** maps;
	Image* pauseScreen;
	Image* icon;
	Image* blockFrame;
	Image* howToPlay;
	Image* levelComplete;

	Image* title;
	Image* mousePtr;

	

	//Image* menuBackground;
	Image* creditScreen;
	Image* splashScreen;
	Image* pressAnyKey;
	Image* menuButton;
	Image* menuNumbers;
	Image* locked;
	Image* menuhud;

	~ImgHolder();
	static ImgHolder* getInst();

	Image* getMaps(int i);
};

#endif