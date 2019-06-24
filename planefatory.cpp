#include "planefatory.h"

planefatory::planefatory(QWidget *pp=0):p(pp),l1(-1),l2(-1),l3(-1)
{

}

QList<enemy*>* planefatory::enemyfactory(int sc=0){
    for (;l1<sc/10*2+sc%10/2;l1++)
    {
        elist.append(new enemy(0 ,0,34,24,10,1,1,p,QString(":/resource/enemy_l1")));
        elist[elist.length()-1]->show();
        QThread::usleep(99);
    }
    for (;l2<sc/10+sc%10/3;l2++)
    {
        elist.append(new enemy(0 ,0,46,60,30,3,0.6,p,QString(":/resource/enemy_l2")));
        elist[elist.length()-1]->show();
        QThread::usleep(99);
    }
    for (;l3<sc/10;l3++)
    {
        elist.append(new enemy(0 ,0,110,164,55,5,0.4,p,QString(":/resource/enemy_l3")));
        elist[elist.length()-1]->show();
        QThread::usleep(99);
    }
    l1--;
    return &elist;
}

void planefatory::moves()
{
    for (int i=0;i<elist.length();i++){
        elist.at(i)->move();
        if(elist.at(i)->getcy()>800+elist.at(i)->getr()+1){
            if (elist.at(i)->getsp()==1)
                l1--;
            else if(elist.at(i)->getsp()==0.6)
                l2--;
            else if(elist.at(i)->getsp()==0.4)
                l3--;
            delete elist.operator [](i);
            elist.removeAt(i);
            if (i>0)
                i--;
        }
    }
}

QList<enemy*>* planefatory::getel()
{
    return &elist;
}
