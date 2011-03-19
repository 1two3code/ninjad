#include "SndHolder.h"

SndHolder* SndHolder::pInstance = NULL;

SndHolder::SndHolder()
{
	click.LoadFromFile("./data/audio/mouse click 2.wav");
	sndClick.SetBuffer(click);

	yay.LoadFromFile("./data/audio/yay.wav");
	sndYay.SetBuffer(yay);
	sndYay.SetPitch(2.0f);

	spring.LoadFromFile("./data/audio/spring.wav");
	sndSpring.SetBuffer(spring);

	drumroll.LoadFromFile("./data/audio/drumroll.wav");
	musDrumroll.SetBuffer(drumroll);

	theme.LoadFromFile("./data/audio/gp.wav");
	musTheme.SetBuffer(theme);

	soundOn = true;
	sndOn(soundOn);
}

void SndHolder::onoff()
{
	if(soundOn == true)
		soundOn = false;
	else
		soundOn = true;

	sndOn(soundOn);
}

void SndHolder::sndOn(bool on)		//bool elgiganten ftw
{
	if(on)
	{
		sndYay.SetVolume(30.0f);
		sndClick.SetVolume(100.0f);
		sndSpring.SetVolume(100.0f);
		musDrumroll.SetVolume(100.0f);
		musTheme.SetVolume(100.0f);
	}
	else
	{
		sndYay.SetVolume(0.0f);
		sndClick.SetVolume(0.0f);
		sndSpring.SetVolume(0.0f);
		musDrumroll.SetVolume(0.0f);
		musTheme.SetVolume(0.0f);
	}
}

SndHolder::~SndHolder()
{
}

SndHolder* SndHolder::getInst()
{
	if(pInstance == NULL)
		pInstance = new SndHolder();

	return pInstance;
}
