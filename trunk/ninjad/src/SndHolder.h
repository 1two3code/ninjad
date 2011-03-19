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
	SoundBuffer drumroll;
	SoundBuffer theme;

	Sound sndClick;
	Sound sndYay;
	Sound sndSpring;
	Sound musDrumroll;
	Sound musTheme;
	bool soundOn;

	void onoff();
	void sndOn(bool on);

	~SndHolder();
	static SndHolder* getInst();
};

#endif