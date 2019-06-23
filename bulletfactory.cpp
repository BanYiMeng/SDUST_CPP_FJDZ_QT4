#include "bulletfactory.h"

bulletfactory::bulletfactory(QWidget *pp=0):p(pp)
{

}

QList<e_bullet*>* bulletfactory::e_creator(QList<flyobjects *> e, flyobjects *m, int x=0)
{

}

QList<f_bullet*>* bulletfactory::f_creator(flyobjects *m, int x=0)
{
    if(x==0)
    {
        fblist.append(new f_bullet(0,0,20,45,-4,0,4+m->getsp(),p,QString(":/resource/bullet_l1")));
        fblist[fblist.length()-1]->setp(m);
        fblist[fblist.length()-1]->show();
        QThread::usleep(99);
    }
    else if (x==1)
    {
        fblist.append(new f_bullet(-20,20,15,30,-5,0,4.5+m->getsp(),p,QString(":/resource/bullet_l2")));
        fblist[fblist.length()-1]->setp(m);
        fblist[fblist.length()-1]->show();
        fblist.append(new f_bullet(20,20,15,30,-5,0,4.5+m->getsp(),p,QString(":/resource/bullet_l2")));
        fblist[fblist.length()-1]->setp(m);
        fblist[fblist.length()-1]->show();
        QThread::usleep(99);
    }
    else if (x==2)
    {
        fblist.append(new f_bullet(0,0,30,55,-100,0,2.5+m->getsp(),p,QString(":/resource/missile")));
        fblist[fblist.length()-1]->setp(m);
        fblist[fblist.length()-1]->show();
        QThread::usleep(99);
    }
    else
    {
        fblist.append(new f_bullet(0,0,20,45,-4,0,4+m->getsp(),p,QString(":/resource/bullet_l1")));
        fblist[fblist.length()-1]->setp(m);
        fblist[fblist.length()-1]->show();
        QThread::usleep(999);
    }
    return &fblist;
}

void bulletfactory::moves()
{
    for (int i=0;i<fblist.length();i++)
        fblist.at(i)->move();
}
