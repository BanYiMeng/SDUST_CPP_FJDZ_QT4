#include "enemy.h"

enemy::enemy(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p)
{
    qsrand(time(NULL));
    if (qrand()%3==0)
    {
        dx=0-w;
        dy=qrand()%311+90-h;
    }
    else if (qrand()%3==1)
    {
        dx=600-w;
        dy=qrand()%311+90-h;
    }
    else
    {
        dy=0-h;
        dx=qrand()%441+80-w;
    }
    sx=qrand()%501+50-dx;
    sy=800-dy;
    sx/=sqrt(sx*sx+sy*sy)/sp;
    sy/=sqrt(sx*sx+sy*sy)/sp;
    a=atan(sy/sx);
}
