#include "enemy.h"

enemy::enemy(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0,const QString &in=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p)
{
    ql = new QLabel(frame);
    ql->resize(w,h);
    pix=new QPixmap(in);
    frame->setWindowFlags(Qt::WindowStaysOnTopHint);
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
    sx=qrand()%401+100-x;
    sy=800-y;
    sx/=sqrt(sx*sx+sy*sy)/sp;
    sy/=sqrt(sx*sx+sy*sy)/sp;
    a=atan(sy/sx);
}

void enemy::move()
{
    y+=sy;
    x+=sx;
    setmove();
}

void enemy::fall()
{
    if(sc==1){
        qm = new QMovie(":/resource/enemy_l1_b.gif");
        QTimer::singleShot(401,this,SLOT(remover()));
    }
    else if(sc==3){
        qm = new QMovie(":/resource/enemy_l2_b.gif");
        QTimer::singleShot(481,this,SLOT(remover()));
    }
    else if(sc==5){
        qm = new QMovie(":/resource/enemy_l3_b.gif");
        QTimer::singleShot(541,this,SLOT(remover()));
    }
    ql->setMovie(qm);
    ql->show();
    qm->start();
}

void enemy::remover()
{
    delete qm;
    delete ql;
    this->deleteLater();
}
