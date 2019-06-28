#ifndef ENEMY_H
#define ENEMY_H

#include <QTimer>
#include <QLabel>
#include <QMovie>
#include "special.h"
#include "flyobjects.h"

class enemy : public flyobjects
{
    Q_OBJECT

public:
    enemy(double,double,int,int,int,int,double,QWidget *,const QString &);
    void move();
    void fall();
private:
    QLabel *ql;
    QMovie *qm;
    double sx,sy;
    double a;
private slots:
    void remover();
};

#endif // ENEMY_H
