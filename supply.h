#ifndef SUPPLY_H
#define SUPPLY_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "flyobjects.h"
#include "flyer.h"
#include <ctime>

class supply:public flyobjects
{
public:
    supply(double,double,int,int,int,int,double,QWidget *,flyer*);
    ~supply();
    void move();
    void update();
    void creator();
private:
    double sx,sy;
    flyer *f;
};

#endif // SUPPLY_H
