#include "SndHolder.h"

SndHolder* SndHolder::pInstance = NULL;

SndHolder::SndHolder()
{
	click.LoadFromFile("./data/audio/mouse click 2.wav");
	sndClick.SetBuffer(click);

	yay.LoadFromFile("./data/audio/yay.wav");
	sndYay.SetBuffer(yay);
	sndYay.SetPitch(2.0f);
	sndYay.SetVolume(30.0f);	
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
