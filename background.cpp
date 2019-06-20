#include "background.h"

background::background(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p)
{
    pix=new QPixmap(":/resource/longplaybackground.jpg");
}


void background::move()
{
    if (y!=0)
        y++;
    else
        y=-800;
    setmove();
}

void background::fall()
{

}
