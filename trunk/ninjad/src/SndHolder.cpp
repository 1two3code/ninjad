#include "SndHolder.h"

SndHolder* SndHolder::pInstance = NULL;

SndHolder::SndHolder()
{
	click.LoadFromFile("./data/audio/mouse click 2.ogg");
	sndClick.SetBuffer(click);

	yay.LoadFromFile("./data/audio/yay.ogg");
	sndYay.SetBuffer(yay);
	sndYay.SetPitch(2.0f);

	scream.LoadFromFile("./data/audio/wscream.ogg");
	sndScream.SetBuffer(scream);

	suction.LoadFromFile("./data/audio/suction.ogg");
	sndSuction.SetBuffer(suction);

	spring.LoadFromFile("./data/audio/spring.ogg");
	sndSpring.SetBuffer(spring);

	drumroll.LoadFromFile("./data/audio/drumroll.ogg");
	musDrumroll.SetBuffer(drumroll);

	theme.LoadFromFile("./data/audio/gp_loop.ogg");
	musTheme.SetBuffer(theme);

	intro.LoadFromFile("./data/audio/gp_intro.ogg");
	musIntro.SetBuffer(intro);

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
		sndClick.SetVolume(30.0f);
		sndSpring.SetVolume(30.0f);
		sndSuction.SetVolume(60.0f);
		sndScream.SetVolume(15.0f);
		musDrumroll.SetVolume(40.0f);
		musTheme.SetVolume(15.0f);
		musIntro.SetVolume(15.0f);
	}
	else
	{
		sndYay.SetVolume(0.0f);
		sndClick.SetVolume(0.0f);
		sndSpring.SetVolume(0.0f);
		sndSuction.SetVolume(0.0f);
		sndScream.SetVolume(0.0f);
		musDrumroll.SetVolume(0.0f);
		musTheme.SetVolume(0.0f);
		musIntro.SetVolume(0.0f);
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
