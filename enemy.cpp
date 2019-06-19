#include "enemy.h"

enemy::enemy(int xx=0,int yy=0,int ww=0,int hh=0,int tt=0,int cc=0,int pp=0):flyobjects(xx,yy,ww,hh,tt,cc,pp)
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
    int tmp;
    sx=qrand()%5;
    sy=qrand()%5;
    tmp=sx*sx+sy*sy;
    sx/=tmp/sp;
    sy/=tmp/sp;
}
