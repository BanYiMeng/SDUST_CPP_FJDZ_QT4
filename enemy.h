#ifndef ENEMY_H
#define ENEMY_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <flyobjects.h>

class enemy : public flyobjects
{
public:
    enemy(double,double,int,int,int,int,double,QWidget *);
private:
    double dx,dy,sx,sy;
    int a;
};

#endif // ENEMY_H
