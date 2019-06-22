#ifndef PLANEFATORY_H
#define PLANEFATORY_H

#include "enemy.h"

class planefatory
{
public:
    QList<enemy*>* enemyfactory(int ,int ,double ,QWidget *);
    planefatory();
private:
    QList<enemy*> qlist;
};

#endif // PLANEFATORY_H
