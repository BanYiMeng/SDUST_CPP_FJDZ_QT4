#include "bullet.h"


Bullet::Bullet(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0,QString b=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p),sx(0),sy(0)
{
    pix=new QPixmap(b);

}

Bullet::~Bullet()
{
}

 void Bullet::setp(flyobjects *in)
{
    x+=in->getcx()-(double)w/2;
    y+=in->getcy();
}

void Bullet::setmove()
{
    frame->move(x,y);
    r=w/2;
    cx=x+w/2;
    cy=y-1;
}

