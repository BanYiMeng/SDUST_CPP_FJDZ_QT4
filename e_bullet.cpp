#include "e_bullet.h"

e_bullet::e_bullet(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0,QString b=0):Bullet(xx,yy,ww,hh,tt,cc,pp,p,b)
{

}

void e_bullet::aim(flyobjects *e,flyobjects *m)
{
    sx=m->getcx()-e->getcx();
    sy=m->getcy()-e->getcy();
    sx/=sqrt(sx*sx+sy*sy)/sp;
    sy/=sqrt(sx*sx+sy*sy)/sp;
}

void e_bullet::move()
{
    y+=sy;
    x+=sx;
    setmove();
}
