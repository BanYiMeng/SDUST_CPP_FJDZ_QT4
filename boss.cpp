#include "boss.h"

boss::boss(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p)
{
    pix = new QPixmap(":/resource/boss_l1");
    frame->setWindowFlags(Qt::WindowStaysOnTopHint);
}

void boss::strike(QList<f_bullet*>* ql){
    int t=0;
        for(int i=0;i<ql->length();i++){
            if ((r+ql->at(i)->getr())*(r+ql->at(i)->getr())>(cx-ql->at(i)->getcx())*(cx-ql->at(i)->getcx())+(cy-ql->at(i)->getcy())*(cy-ql->at(i)->getcy())){
                if (llt(ql->at(i)->llt(0))<=0)
                {
                    t+=sc;
                    delete this;
                    delete ql->operator [](i);
                    ql->removeAt(i);
                    i=-1;
                }
                else
                {
                   delete ql->operator [](i);
                   ql->removeAt(i);
                   if (i>=0)
                       i--;
                }
                //if (!ql->length())
                    //return t;

        }
    }
}

void boss::move(){
    if(x>260)
        x--;
    if(x<260)
        x++;
    if(y<0)
        y++;
    if(y>0)
        y--;
}
