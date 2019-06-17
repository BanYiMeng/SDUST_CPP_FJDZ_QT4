#ifndef FLYER_H
#define FLYER_H

#include"flyobjects.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class flyer : public flyobjects
{
public:
    flyer(int,int,int,int,int,int,int);
};

#endif // FLYER_H
