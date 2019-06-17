#ifndef FLYER_H
#define FLYER_H

#include"flyobjects.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>

typedef enum {UP, DOWN, LEFT, RIGHT} CHECK_FLAG;

class flyer : public flyobjects
{
public:
    flyer(int,int,int,int,int,int,int);
    ~flyer();
    void setpix();//change pix;
    void paint();
    void fall();
    void shoot();
    void strike();
    void move(QString);
protected:
    int blood;
    QPixmap *pix;
    int direction;
};

#endif // FLYER_H
//
