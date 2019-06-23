#include "flyobjects.h"

flyobjects::flyobjects(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0):w(ww),h(hh),lt(tt),sc(cc),r(sqrt(1.0*ww*ww/4+1.0*hh*hh/4)),x(xx),y(yy),sp(pp),cx(xx+(double)ww/2),cy(yy+(double)hh/2)
{
    frame = new QFrame;
    frame->setParent(p);
}
flyobjects::~flyobjects(){
    delete frame;
    delete pix;
}

void flyobjects::show(){
    frame->resize(w,h);
    QPalette palette;
    palette.setBrush(frame->backgroundRole(),QBrush(*pix));
    frame->setPalette(palette);
    frame->setMask(pix->mask());  //可以将图片中透明部分显示为透明的
    frame->setAutoFillBackground(true);
    frame->move(x,y);
    frame->show();
}

void flyobjects::setmove(){
    frame->move(x,y);
    cx=x+w/2;
    cy=y+h/2;
}

double flyobjects::getcx()
{
    return cx;
}

double flyobjects::getcy()
{
    return cy;
}

void flyobjects::setsp(int x=0)
{
    sp=x;
}

double flyobjects::getsp()
{
    return sp;
}

int flyobjects::llt(int x)
{
    lt+=x;
    return lt;
}

int flyobjects::getr()
{
    return r;
}

int flyobjects::getsc()
{
    return sc;
}
