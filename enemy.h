#ifndef ENEMY_H
#define ENEMY_H

#include <QTime>
#include <flyobjects.h>

class enemy : public flyobjects
{
public:
    enemy(double,double,int,int,int,int,double,QWidget *,const QString &);
    void move();
private:
    double sx,sy;
    int a;
};

#endif // ENEMY_H
