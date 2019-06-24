#include "bulletfactory.h"

bulletfactory::bulletfactory(QWidget *pp=0):p(pp)
{

}

void bulletfactory::e_creator(QList<enemy*> *e, flyobjects *m, int x=0)
{
    for (int i=0;i<e->length();i++)
    {
        eblist.append(new e_bullet(e->at(i)->getcx()-16,e->at(i)->getcy()-16,24,24,-3,0,3,p,QString(":/resource/enemy_bullet_l1")));
        eblist[eblist.length()-1]->aim(e->at(i),m);
        eblist[eblist.length()-1]->show();
        QEventLoop loop;
        QTimer::singleShot(100, &loop, SLOT(quit()));
        loop.exec();
    }
}

void bulletfactory::f_creator(flyobjects *m, int x=0)
{
    if(x==0)
    {
        fblist.append(new f_bullet(0,-85,20,45,-4,0,4+m->getsp(),p,QString(":/resource/bullet_l1")));
        fblist[fblist.length()-1]->setp(m);
        fblist[fblist.length()-1]->show();
        QThread::usleep(99);
    }
    else if (x==1)
    {
        fblist.append(new f_bullet(-20,-25,15,30,-5,0,4.5+m->getsp(),p,QString(":/resource/bullet_l2")));
        fblist[fblist.length()-1]->setp(m);
        fblist[fblist.length()-1]->show();
        fblist.append(new f_bullet(20,-25,15,30,-5,0,4.5+m->getsp(),p,QString(":/resource/bullet_l2")));
        fblist[fblist.length()-1]->setp(m);
        fblist[fblist.length()-1]->show();
        QThread::usleep(99);
    }
    else if (x==2)
    {
        fblist.append(new f_bullet(0,-105,30,55,-100,0,2.5+m->getsp(),p,QString(":/resource/missile")));
        fblist[fblist.length()-1]->setp(m);
        fblist[fblist.length()-1]->show();
        QThread::usleep(99);
    }
    else
    {
        fblist.append(new f_bullet(0,-85,20,45,-4,0,4+m->getsp(),p,QString(":/resource/bullet_l1")));
        fblist[fblist.length()-1]->setp(m);
        fblist[fblist.length()-1]->show();
        QThread::usleep(99);
    }
}

void bulletfactory::moves()
{
    for (int i=0;i<fblist.length();i++){
        fblist.at(i)->move();
        if(fblist.at(i)->getcy()<-50){
            delete fblist.operator [](i);
            fblist.removeAt(i);
            if (i>0)
                i--;
        }
    }
    for (int i=0;i<eblist.length();i++){
        eblist.at(i)->move();
    if(eblist.at(i)->getcy()<-50||eblist.at(i)->getcy()>850){
        delete eblist.operator [](i);
        eblist.removeAt(i);
        if (i>0)
            i--;
    }
    }
}

QList<e_bullet*>* bulletfactory::getebl()
{
    return &eblist;
}

QList<f_bullet*>* bulletfactory::getfbl()
{
    return &fblist;
}
