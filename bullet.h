#ifndef BULLET_H
#define BULLET_H

#include <QtWebKit>
#include <QLabel>
#include <QMovie>
#include "special.h"
#include "flyobjects.h"

class Bullet:public flyobjects
{
     Q_OBJECT

public:
    Bullet(double,double,int,int,int,int,double,QWidget *,QString);
    void setp(flyobjects *);
    void setmove();
    void fall();
protected:
    double sx,sy;
    QLabel *ql;
    QMovie *qm;
private slots:
    void remover();
};

#endif // BULLET_H
