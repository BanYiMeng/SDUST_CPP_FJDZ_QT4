#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include <QThread>
#include <QTimer>
#include <QtCore>
#include "e_bullet.h"
#include "f_bullet.h"
#include "enemy.h"

class bulletfactory : public QThread
{
public:
    bulletfactory(QWidget *);
    void f_creator(flyobjects *,int);
    void e_creator(QList<enemy*>*,flyobjects*,int);
    void moves();
    QList<f_bullet*>* getfbl();
    QList<e_bullet*>* getebl();
private:
    QWidget *p;
    QList<e_bullet*> eblist;
    QList<f_bullet*> fblist;
};

#endif // BULLETFACTORY_H
