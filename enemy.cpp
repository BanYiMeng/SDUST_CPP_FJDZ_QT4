#include "enemy.h"

enemy::enemy(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0):flyobjects(xx,yy,ww,hh,tt,cc,pp)
{
    qsrand(time(NULL));
    if (qrand()%3==0)
    {
        dx=0-w;
        dy=qrand()%401-h;
    }
    else if (qrand()%3==1)
    {
        dx=600-w;
        dy=qrand()%401-h;
    }
    else
    {
        dy=0-h;
        dx=qrand()%601-w;
    }
    sx=qrand()%601-dx;
    sy=800-dy;
    sx/=sqrt(sx*sx+sy*sy)/sp;
    sy/=sqrt(sx*sx+sy*sy)/sp;
}
