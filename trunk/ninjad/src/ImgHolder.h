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
	Image* blocks;
	Image* ninja;
	Image** maps;
	Image* colorCode;
	Image* player;
	~ImgHolder();
	static ImgHolder* getInst();

	Image* getMaps(int i);
};

#endif