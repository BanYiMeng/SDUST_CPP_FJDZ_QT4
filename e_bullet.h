#ifndef E_BULLET_H
#define E_BULLET_H

#include "bullet.h"

class e_bullet : public Bullet
{
public:
    e_bullet(double,double,int,int,int,int,double,QWidget *,QString);
    void aim(flyobjects *,flyobjects *);
    void move();
    void b1_l1(double,double);
};

#endif // E_BULLET_H
