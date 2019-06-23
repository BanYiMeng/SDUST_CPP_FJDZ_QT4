#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include <QThread>
#include "e_bullet.h"
#include "f_bullet.h"

class bulletfactory : public QThread
{
public:
    bulletfactory(QWidget *);
    QList<f_bullet*>* f_creator(flyobjects *,int);
    QList<e_bullet*>* e_creator(QList<flyobjects*>,flyobjects*,int);
    void moves();
private:
    QWidget *p;
    QList<e_bullet*> eblist;
    QList<f_bullet*> fblist;
};

#endif // BULLETFACTORY_H
