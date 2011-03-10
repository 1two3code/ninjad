#include "StdNinja.h"

StdNinja::StdNinja(int s)
{
		

        setActive(false);
		//<-- S�tter ocks� mirroredX, dirX och dirY
        setSpeed(2);
        setDrawn(false);
        setComplete(false);

        //SetSubRect(IntRect(0,0,16,16));
        //SetPosition(208,112);
        //FlipX(true);
		this->curAnim = NULL;
		this->runAnim = new Animation(ImgHolder::getInst()->ninRun, 4, 16, 16, 2, true, true);
		this->slideAnim = new Animation(ImgHolder::getInst()->ninSlide, 1, 16, 16, 1, true, false);
		this->runAnim->sprite.SetCenter(8,8);
		this->slideAnim->sprite.SetCenter(8,8);
		//this->curAnim = this->runAnim;
        //this->SetRotation(90);
        //SetCenter(0,0);
		setState(s);
        
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
                Alla ska kolla f�rst �t x sen �t (dirX, dirY) efter kollision
                case 0 och 6, (dirX, 1)
                case 1 och 7, (-1, dirY)
                case 2 och 4, (dirX, -1)
                case 3 och 5, (1, dirY)
        */
        switch(this->getState())
        {
        case 0:         //riktning �t v�nster, huvudet upp
				if(this->curAnim)this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->runAnim;
				this->curAnim->MirX(false);
				this->curAnim->sprite.SetRotation(0);
                setDirX(-1);
                setDirY(0);
                break;
        case 1:         //riktning Ner�t, huvudet �t v�nster
				if(this->curAnim)this->slideAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->slideAnim;
                this->curAnim->MirX(true);
                //this->curAnim->sprite.SetRotation(90);
                setDirX(0);
                setDirY(1);
                break;
        case 2:         //riktning h�ger, huvudet ner�t
				if(this->curAnim)this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->runAnim;
                this->curAnim->MirX(false);
                this->curAnim->sprite.SetRotation(180);
                setDirX(1);
                setDirY(0);
                break;
        case 3:         //riktning upp�t, huvudet �t h�ger
				if(this->curAnim)this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->runAnim;
                this->curAnim->MirX(false);
                this->curAnim->sprite.SetRotation(-90);
                setDirX(0);
                setDirY(-1);
                break;
        case 4:         //riktning v�nster, huvudet ner�t
				if(this->curAnim)this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->runAnim;
                this->curAnim->MirX(true);
                this->curAnim->sprite.SetRotation(180);
                setDirX(-1);
                setDirY(0);
                break;
        case 5:         //riktning ner�t, huvudet �t h�ger
				if(this->curAnim)this->slideAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->slideAnim;
                this->curAnim->MirX(false);
				this->curAnim->MirY(false);
                //this->curAnim->sprite.SetRotation(-90);
                setDirX(0);
                setDirY(1);
                break;
        case 6:         //riktning h�ger, huvudet upp�t
				if(this->curAnim)this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->runAnim;
                this->curAnim->MirX(true);
                this->curAnim->sprite.SetRotation(0);
                setDirX(1);
                setDirY(0);
                break;
        case 7:         //riktning upp�t, huvudet �t v�nster
				if(this->curAnim)this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->runAnim;
                this->curAnim->MirX(true);
                this->curAnim->sprite.SetRotation(90);
                setDirX(0);
                setDirY(-1);
                break;
        case 8:         //faller ner�t, ingen spegling, ingen rotation
				if(this->curAnim)this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->runAnim;
                setDirX(0);
                setDirY(1);
                break;
        case 9:         //flyger upp�t
				if(this->curAnim)this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
				this->curAnim = this->runAnim;
                setDirX(0);
                setDirY(-1);
                break;
        default:
                break;
		}
}