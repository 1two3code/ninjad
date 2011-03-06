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
	Image* ninja;
	Image** maps;
	Image* colorCode;
	Image* player;
	Image* pauseScreen;

	//Image* menuBackground;
	Image* splashScreen;
	Image* menuButton;
	Image* menuNumbers;
	Image* locked;
	Image* hand;
	~ImgHolder();
	static ImgHolder* getInst();

	Image* getMaps(int i);
};

#endif