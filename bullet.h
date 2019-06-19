#ifndef BULLET_H
#define BULLET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPrinter>
#include <QGraphicsItem>
#include "flyobjects.h"

class Bullet:public flyobjects
{
public:
    Bullet(double,double,int,int,int,int,double,QWidget *);
};

#endif // BULLET_H
