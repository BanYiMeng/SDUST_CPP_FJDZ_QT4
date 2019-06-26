#include "boss.h"

boss::boss(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0,QWidget *p=0):flyobjects(xx,yy,ww,hh,tt,cc,pp,p),pt(p)
{
    pix = new QPixmap(":/resource/boss_l1");
    frame->setWindowFlags(Qt::WindowStaysOnTopHint);
    direct=1;
}

boss::~boss(){

}

bool boss::strike(QList<f_bullet*>* ql){
    int t=0;
        for(int i=0;i<ql->length();i++){
            if ((r+ql->at(i)->getr())*(r+ql->at(i)->getr())>(cx-ql->at(i)->getcx())*(cx-ql->at(i)->getcx())+(cy-ql->at(i)->getcy())*(cy-ql->at(i)->getcy())){
                if (llt(ql->at(i)->llt(0))<=0)
                {
                    t+=sc;
                    delete ql->operator [](i);
                    ql->removeAt(i);
                    i=-1;
                    return true;
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
        return false;
}

void boss::move(){
    x+=direct;
    if(x==520)
        direct=-1;
    else if(x==0)
        direct=1;
    if(y<90)
        y++;
    setmove();
}

void boss::fall(){

}

void boss::shoot(QList<e_bullet*> *eblist){
    if (cx<599&&cx>1&&cy>1&&cy<799)
    {
        for (int i=-60;i<=60;i+=15)
        {
            eblist->append(new e_bullet(cx-16,cy-16,24,24,-3,0,3,pt,QString(":/resource/enemy_bullet_l1")));
            eblist->operator [](eblist->length()-1)->b1_l1(sp*sin(i*3.1415926/180),sp*cos(i*3.1415926/180));
            eblist->operator [](eblist->length()-1)->show();
        }
    }
}
