#include "supply.h"

supply::supply(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0,flyer *ff=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p),f(ff)
{
    pix = new QPixmap(":resource/-1.png");
}

supply::~supply()
{

}

void supply::update()
{
    if ((f->getr()+r)*(f->getr()+r)>(f->getcx()-cx)*(f->getcx()-cx)+(f->getcy()-cy)*(f->getcy()-cy))
    {
        if (sc==1)
            f->optt(sc-f->optt(0));
        else if (sc==2)
            f->optt(sc-f->optt(0));
        else
            if (f->llt(0)<8&&f->llt(0)>0)
                f->llt(1);
        delete pix;
        pix=new QPixmap(":resource/-1.png");
        sx=sy=0;
        x=-50;
        y=-50;
    }

}

void supply::creator()
{
    qsrand(time(NULL));
    int i=qrand()%3;
    if (i==0)
    {
        x=0-w;
        y=qrand()%81+90-h;
    }
    else if (i==1)
    {
        x=600+w;
        y=qrand()%81+90-h;
    }
    else
    {
        y=0-h;
        x=qrand()%(441-w)+80;
    }
    sx=qrand()%451+50-x;
    sy=800-y;
    sx/=sqrt(sx*sx+sy*sy)/sp;
    sy/=sqrt(sx*sx+sy*sy)/sp;
    if(i==1)  {
        pix = new QPixmap(":resource/upgrade_bl2");//up to bullet_l2
        sc=1;
    }
    else if(i==2) {
        pix = new QPixmap(":resource/upgrade_missile");//up to missile
        sc=2;
    }
    else {
        pix = new QPixmap(":resource/add_life");//add life
        sc=3;
    }
    show();
}

void supply::move()
{
    if (y>900)
    {
        delete pix;
        pix=new QPixmap(":resource/-1.png");
        sx=sy=0;
        x=-50;
        y=-50;
    }
    x+=sx;
    y+=sy;
    setmove();
}

