#ifndef FLYER_H
#define FLYER_H

#include "flyobjects.h"


typedef enum {UP, DOWN, LEFT, RIGHT} CHECK_FLAG;

class flyer : public flyobjects
{
public:
    flyer(int,int,int,int,int,int,int,QWidget *);
    ~flyer();
    void setpix();//change pix;
    void paint();
    void fall();
    void shoot();
    void strike();
    void show();
    void move(QString);
protected:
    int blood;
    int direction;
    QPixmap *pix;
    QFrame *frame;
};

#endif // FLYER_H
//
