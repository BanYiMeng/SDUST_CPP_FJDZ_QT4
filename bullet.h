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
    Bullet(int,int,int,int,int,int,int,const QPixmap *, QGraphicsScene *, QGraphicsItem *);
};

#endif // BULLET_H
