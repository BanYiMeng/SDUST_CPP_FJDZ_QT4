#include "flyer.h"

flyer::flyer(int xx=0,int yy=0,int ww=0,int hh=0,int tt=0,int cc=0,int pp=0):flyobjects(xx,yy,ww,hh,tt,cc,pp),blood(100){
    direction=0;
}

void flyer::setpix(){
    pix->load("resource/logo.jpg");//change our plane's pix;
}

void flyer::fall(){
    if(blood==0){
        pix->load("JPG");//change bomb pix;
        //还要加声音和消失的代码；
    }
}

void flyer::move(QString s){
    if(s=="up"&&y>0)
        y-=40;
    if(s=="down"&&y<800)
        y+=40;
    if(s=="left"&&x>0)
        x-=40;
    if(s=="right"&&x<600)
        x+=40;
}
