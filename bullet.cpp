#include "bullet.h"

Bullet::Bullet(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,const QPixmap *pixs=NULL, QGraphicsScene *scene=NULL, QGraphicsItem *parent=NULL):flyobjects(xx,yy,ww,hh,tt,cc,pp)
{
    r=w/2;
    cx=x+w/2;
    cy=y;
}
