#include "flyer.h"

flyer::flyer(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p),t(0){
    r/=2;
    pix = new QPixmap(":/resource/user");
    frame->setWindowFlags(Qt::WindowStaysOnTopHint);
}

flyer::~flyer(){

}

bool flyer::fall(){
    pix->load("JPG");
    return true;
}

void flyer::move(QString s){
    if(s=="up"&&y>0)
        y-=3;
    if(s=="down"&&y<718)
        y+=3;
    if(s=="left"&&x>0)
        x-=3;
    if(s=="right"&&x<540)
        x+=3;
}

void flyer::wudi(){
    lt=-1;
}

void flyer::setsc(int i=0)
{
    sc+=i;
}

int flyer::optt(int i=0)
{
    t+=i;
    return t;
}
