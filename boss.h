#ifndef BOSS_H
#define BOSS_H

#include "flyobjects.h"
#include "flyer.h"
#include "f_bullet.h"
#include "e_bullet.h"

class boss:public flyobjects
{
public:
    boss(double ,double ,int ,int ,int ,int ,double ,QWidget* );
    ~boss();
    bool strike(QList<f_bullet*>*);
    void move();
    void fall();
    void shoot(QList<e_bullet*>*);
private:
    int direct;
    QWidget *pt;
};

#endif // BOSS_H
