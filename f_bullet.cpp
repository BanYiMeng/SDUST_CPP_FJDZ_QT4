#include "f_bullet.h"

f_bullet::f_bullet(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0,QString b=0):Bullet(xx,yy,ww,hh,tt,cc,pp,p,b)
{

}

void f_bullet::move()
{
    y-=sp;
    setmove();
}
