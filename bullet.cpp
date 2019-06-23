#include "bullet.h"


Bullet::Bullet(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0,QString b=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p)
{
    pix=new QPixmap(b);
}

Bullet::~Bullet()
{

}

 void Bullet::setp(flyobjects *in)
{
    x+=in->getx()+in->getw()/2-(double)w/2;
    y+=in->gety()-1-h;
}

void Bullet::setmove()
{
    frame->move(x,y);
    r=w/2;
    cx=x+w/2;
    cy=y-1;
}
