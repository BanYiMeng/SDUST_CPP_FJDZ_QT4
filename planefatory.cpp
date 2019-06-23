#include "planefatory.h"

planefatory::planefatory(QWidget *pp=0):p(pp),l1(-1),l2(-1),l3(-1)
{

}

QList<enemy*>* planefatory::enemyfactory(int sc=0){
    for (;l1<sc/1000*2+sc%1000/100;l1++)
    {
        elist.append(new enemy(0 ,0,34,24,10,100,1,p,QString(":/resource/enemy_l1")));
        elist[elist.length()-1]->show();
        QThread::usleep(99);
    }
    for (;l2<sc/1000+sc%1000/200;l2++)
    {
        elist.append(new enemy(0 ,0,46,60,30,300,0.6,p,QString(":/resource/enemy_l2")));
        elist[elist.length()-1]->show();
        QThread::usleep(99);
    }
    for (;l3<sc/1000;l3++)
    {
        elist.append(new enemy(0 ,0,110,164,55,500,0.4,p,QString(":/resource/enemy_l3")));
        elist[elist.length()-1]->show();
        QThread::usleep(99);
    }
    return &elist;
}

void planefatory::moves()
{
    for (int i=0;i<elist.length();i++)
        elist.at(i)->move();
}

QList<enemy*>* planefatory::getel()
{
    return &elist;
}
