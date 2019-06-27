#ifndef BULLET_H
#define BULLET_H

#include <QtWebKit>
#include "flyobjects.h"

class Bullet:public flyobjects
{
public:
    Bullet(double,double,int,int,int,int,double,QWidget *,QString);
    ~Bullet();
    void setp(flyobjects *);
    void setmove();
protected:
    double sx,sy;
};

#endif // BULLET_H
