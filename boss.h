#ifndef BOSS_H
#define BOSS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "flyobjects.h"
#include "flyer.h"
#include "f_bullet.h"

class boss:public flyobjects
{
public:
    boss(double ,double ,int ,int ,int ,int ,double ,QWidget* );
    void strike(QList<f_bullet*>*);
    void move();
};

#endif // BOSS_H
