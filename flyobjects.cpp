#include "flyobjects.h"

flyobjects::flyobjects(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0):x(xx),y(yy),w(ww),h(hh),lt(tt),sc(cc),sp(pp),cx(xx+ww/2),cy(yy+hh/2),r(sqrt(ww*ww/4+hh*hh/4))
{
    frame = new QFrame;
    frame->setParent(p);
}
flyobjects::~flyobjects(){

}

bool flyobjects::strike(flyobjects *one,flyobjects *two){
    if ((one->r+two->r)*(one->r+two->r)<(one->cx-two->cx)*(one->cx-two->cx)+(one->cy-two->cy)*(one->cy-two->cy)){
        return false;
    }
    else
        return true;
}

void flyobjects::show(){
    frame->resize(w,h);
    QPalette palette;
    palette.setBrush(frame->backgroundRole(),QBrush(*pix));
    frame->setPalette(palette);
    frame->setMask(pix->mask());  //可以将图片中透明部分显示为透明的
    frame->setAutoFillBackground(true);
    frame->setWindowFlags(Qt::FramelessWindowHint);//去掉最小化，关闭按钮
    frame->move(x,y);
    frame->show();
}
