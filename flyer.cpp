#include "flyer.h"

flyer::flyer(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0):flyobjects(xx,yy,ww,hh,tt,cc,pp),blood(100){
    direction=0;
    frame = new QFrame;
    pix = new QPixmap(":/resource/user.png");
    frame->setParent(p);
}

flyer::~flyer(){
    delete pix;
    delete frame;
}

void flyer::show(){
    frame->resize(60,82);
    QPalette   palette;
    palette.setBrush(frame->backgroundRole(),QBrush(*pix));
    frame->setPalette(palette);
    frame->setMask(pix->mask());  //可以将图片中透明部分显示为透明的
    frame->setAutoFillBackground(true);
    frame->setWindowFlags(Qt::FramelessWindowHint);//去掉最小化，关闭按钮
    frame->move(x,y);
    frame->show();
}

void flyer::fall(){
    if(blood==0){
        pix->load("JPG");//change bomb pix;
        //还要加声音和消失的代码；
    }
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

void flyer::setmove(){
    frame->move(x,y);
}
