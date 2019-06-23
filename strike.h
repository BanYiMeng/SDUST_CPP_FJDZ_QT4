#ifndef STRIKE_H
#define STRIKE_H

#include "e_bullet.h"
#include "f_bullet.h"
#include "enemy.h"
#include "flyer.h"

class strike
{
public:
    strike(QList<enemy*> *,QList<e_bullet*> *,QList<f_bullet*> *,flyer *);
    int e2fb();
    void f2e();
    void f2eb();
private:
    QList<enemy*> *el;
    QList<e_bullet*> *ebl;
    QList<f_bullet*> *fbl;
    flyer *f;
};

#endif // STRIKE_H
