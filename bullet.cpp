#include "bullet.h"

Bullet::Bullet(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p)
{
    r=w/2;
    cx=x+w/2;
    cy=y;
}
