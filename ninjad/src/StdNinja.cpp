#include "StdNinja.h"

StdNinja::StdNinja(int s)
{
        setActive(false);
                  //<-- Sätter också mirroredX, dirX och dirY
        setSpeed(2);
        setDrawn(false);
        setComplete(false);
		this->curAnim = NULL;

		this->runAnim = new Animation(ImgHolder::getInst()->ninja, 4, 16, 16, 1, true, true);
        //SetSubRect(IntRect(0,0,16,16));
        //SetPosition(208,112);
        //FlipX(true);
		this->runAnim->sprite.SetCenter(8,8);
		this->curAnim = this->runAnim;
        //this->SetRotation(90);
        setState(s);
        //SetCenter(0,0);
        
}

StdNinja::~StdNinja()
{}

void StdNinja::update()
{
        if(active)
        {
			this->curAnim->Update();
			this->curAnim->sprite.Move((float)getSpeed()*getDirX(), (float)getSpeed()*getDirY());
        }
}

void StdNinja::testmove()
{
        this->curAnim->sprite.Move((float)getSpeed()*getDirX(), (float)getSpeed()*getDirY());
}

void StdNinja::retrace()
{
        this->curAnim->sprite.Move(-(float)getSpeed()*getDirX(), -(float)getSpeed()*getDirY());
}

void StdNinja::updateSprite()
{
        /*
                Alla ska kolla först åt x sen åt (dirX, dirY) efter kollision
                case 0 och 6, (dirX, 1)
                case 1 och 7, (-1, dirY)
                case 2 och 4, (dirX, -1)
                case 3 och 5, (1, dirY)
        */
        switch(this->getState())
        {
        case 0:         //riktning Åt vänster, huvudet upp
				this->curAnim->MirX(false);
				this->curAnim->sprite.SetRotation(0);
                setDirX(-1);
                setDirY(0);
                break;
        case 1:         //riktning Neråt, huvudet åt vänster
                this->curAnim->MirX(false);
                this->curAnim->sprite.SetRotation(90);
                setDirX(0);
                setDirY(1);
                break;
        case 2:         //riktning höger, huvudet neråt
                this->curAnim->MirX(false);
                this->curAnim->sprite.SetRotation(180);
                setDirX(1);
                setDirY(0);
                break;
        case 3:         //riktning uppåt, huvudet åt höger
                this->curAnim->MirX(false);
                this->curAnim->sprite.SetRotation(-90);
                setDirX(0);
                setDirY(-1);
                break;
        case 4:         //riktning vänster, huvudet neråt
                this->curAnim->MirX(true);
                this->curAnim->sprite.SetRotation(180);
                setDirX(-1);
                setDirY(0);
                break;
        case 5:         //riktning neråt, huvudet åt höger
                this->curAnim->MirX(true);
                this->curAnim->sprite.SetRotation(-90);
                setDirX(0);
                setDirY(1);
                break;
        case 6:         //riktning höger, huvudet uppåt
                this->curAnim->MirX(true);
                this->curAnim->sprite.SetRotation(0);
                setDirX(1);
                setDirY(0);
                break;
        case 7:         //riktning uppåt, huvudet åt vänster
                this->curAnim->MirX(true);
                this->curAnim->sprite.SetRotation(90);
                setDirX(0);
                setDirY(-1);
                break;
        case 8:         //faller neråt, ingen spegling, ingen rotation
                setDirX(0);
                setDirY(1);
                break;
        case 9:         //flyger uppåt
                setDirX(0);
                setDirY(-1);
                break;
        default:
                break;
		}
}