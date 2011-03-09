#ifndef SNDHOLDER_H
#define SNDHOLDER_H
#include <SFML\Audio.hpp>

using namespace sf;

class SndHolder
{
private:
	static SndHolder* pInstance;
	SndHolder();

public:
	SoundBuffer click;
	SoundBuffer yay;

	Sound sndClick;
	Sound sndYay;

	~SndHolder();
	static SndHolder* getInst();
};

#endif