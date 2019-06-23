#ifndef F_BULLET_H
#define F_BULLET_H

#include "bullet.h"

class f_bullet : public Bullet
{
public:
    f_bullet(double,double,int,int,int,int,double,QWidget *,QString);
    void move();
};

#endif // F_BULLET_H
