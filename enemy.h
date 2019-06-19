#ifndef ENEMY_H
#define ENEMY_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <flyobjects.h>

class enemy : public flyobjects
{
public:
    enemy(int,int,int,int,int,int,int);
private:
    int dx,dy,sx,sy;
};

#endif // ENEMY_H
