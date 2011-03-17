#include "StdNinja.h"

StdNinja::StdNinja(int s)
{
		

        setActive(false);
		//<-- Sätter också mirroredX, dirX och dirY
        setSpeed(2);
        setDrawn(false);
        setComplete(false);
		setSpeedY(0);
		count=0;

        //SetSubRect(IntRect(0,0,16,16));
        //SetPosition(208,112);
        //FlipX(true);
		this->curAnim = NULL;
		this->runAnim = new Animation(ImgHolder::getInst()->ninRun, 4, 16, 16, 2, true, true);
		this->slideAnim = new Animation(ImgHolder::getInst()->ninSlide, 1, 16, 16, 1, true, true);
		this->fallAnim = new Animation(ImgHolder::getInst()->ninFall, 8, 16, 16, 2, true, true);
		this->climbAnim = new Animation(ImgHolder::getInst()->ninClimb, 4, 16, 16, 2, true, true);
		this->armAnim = new Animation(ImgHolder::getInst()->ninArm, 4, 16, 16, 2, true, true);
		this->runAnim->sprite.SetCenter(8,8);
		this->slideAnim->sprite.SetCenter(8,8);
		this->fallAnim->sprite.SetCenter(8,8);
		this->climbAnim->sprite.SetCenter(8,8);
		this->armAnim->sprite.SetCenter(8,8);
		//this->curAnim = this->runAnim;
        //this->SetRotation(90);
        //SetCenter(0,0);
		setState(s);        
}

StdNinja::~StdNinja()
{}

void StdNinja::update()
{
        if(active && getState()!=10)
        {
			this->curAnim->Update();
			this->curAnim->sprite.Move((float)getSpeed()*getDirX(), (float)getSpeed()*getDirY());
        }
		else if(active && getState()==10)
		{
			this->curAnim->Update();
			this->curAnim->sprite.Move((float)getSpeed()*getDirX(), 0);
			if(count==0)
			{
				this->curAnim->sprite.Move(0, (float)getSpeedY()*getDirX());
				setSpeedY(getSpeedY()+1);
			}

			count++;
			count= count%2;
			if(getSpeedY()>8)
			{
				setState(6);
				count=0;
			}
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
				if(this->curAnim)this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->runAnim;
				this->curAnim->MirX(false);
				this->curAnim->sprite.SetRotation(0);
                setDirX(-1);
                setDirY(0);
				setSpeed(2);
                break;
        case 1:         //riktning Neråt, huvudet åt vänster
				if(this->curAnim)this->slideAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->slideAnim;
                this->curAnim->MirX(true);
                //this->curAnim->sprite.SetRotation(90);
                setDirX(0);
                setDirY(1);
				setSpeed(2);
                break;
        case 2:         //riktning höger, huvudet neråt
				if(this->curAnim)this->armAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->armAnim;
                this->curAnim->MirX(false);
                //this->curAnim->sprite.SetRotation(180);
                setDirX(1);
                setDirY(0);
				setSpeed(2);
                break;
        case 3:         //riktning uppåt, huvudet åt höger
				if(this->curAnim)this->climbAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->climbAnim;
                this->curAnim->MirX(true);
                //this->curAnim->sprite.SetRotation(-90);
                setDirX(0);
                setDirY(-1);
				setSpeed(2);
                break;
        case 4:         //riktning vänster, huvudet neråt
				if(this->curAnim)this->armAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->armAnim;
                this->curAnim->MirX(true);
                //this->curAnim->sprite.SetRotation(180);
                setDirX(-1);
                setDirY(0);
				setSpeed(2);
                break;
        case 5:         //riktning neråt, huvudet åt höger
				if(this->curAnim)this->slideAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->slideAnim;
                this->curAnim->MirX(false);
				//this->curAnim->MirY(false);
                //this->curAnim->sprite.SetRotation(-90);
                setDirX(0);
                setDirY(1);
				setSpeed(2);
                break;
        case 6:         //riktning höger, huvudet uppåt
				if(this->curAnim)this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->runAnim;
                this->curAnim->MirX(true);
                this->curAnim->sprite.SetRotation(0);
                setDirX(1);
                setDirY(0);
				setSpeed(2);
                break;
        case 7:         //riktning uppåt, huvudet åt vänster
				if(this->curAnim)this->climbAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->climbAnim;
                this->curAnim->MirX(false);
                //this->curAnim->sprite.SetRotation(90);
                setDirX(0);
                setDirY(-1);
				setSpeed(2);
                break;
        case 8:         //faller neråt, ingen spegling, ingen rotation
				if(this->curAnim)this->fallAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->fallAnim;
                setDirX(0);
                setDirY(1);
				setSpeed(2);
                break;
        case 9:         //flyger uppåt
				if(this->curAnim)this->fallAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->fallAnim;
                setDirX(0);
                setDirY(-1);
				setSpeed(4);
                break;
		case 10:		//Hoppar åt höger (trampolin)
			if(this->curAnim)this->fallAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->fallAnim;
				//setDirX(1);
				setDirY(1);
				setSpeed(8);
				setSpeedY(-8);
                break;
		}
}