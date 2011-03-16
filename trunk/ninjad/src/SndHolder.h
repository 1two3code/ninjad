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
	SoundBuffer spring;

	Sound sndClick;
	Sound sndYay;
	Sound sndSpring;

	~SndHolder();
	static SndHolder* getInst();
};

#endif