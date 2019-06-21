#include "flyer.h"

flyer::flyer(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p){
    pix = new QPixmap(":/resource/user");
    frame->setWindowFlags(Qt::WindowStaysOnTopHint);
}

flyer::~flyer(){

}

void flyer::fall(){
    if(lt==0){
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

void flyer::wudi(){
    lt=-1;
}
