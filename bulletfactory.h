
#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include <QTimer>
#include "e_bullet.h"
#include "f_bullet.h"
#include "enemy.h"

class bulletfactory : public QObject
{
    Q_OBJECT

public:
    bulletfactory(QList<enemy*> *,flyobjects *,QWidget *);
    void f_creator(int);
    void e_creator(int);
    void moves();
    QList<f_bullet*>* getfbl();
    QList<e_bullet*>* getebl();
private slots:
    void ebmake();

private:
    QWidget *p;
    QList<e_bullet*> eblist;
    QList<f_bullet*> fblist;
    QList<enemy*> *e;
    flyobjects *m;
    int i;
    QTimer *mt;
};

#endif // BULLETFACTORY_H
