#ifndef PLANEFATORY_H
#define PLANEFATORY_H

#include <QThread>
#include "enemy.h"

class planefatory : public QThread
{
public:
    QList<enemy*>* enemyfactory(int);
    planefatory(QWidget *);
    void moves();
private:
    QList<enemy*> elist;
    QWidget *p;
    int l1,l2,l3;
};

#endif // PLANEFATORY_H
