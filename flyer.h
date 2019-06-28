#ifndef FLYER_H
#define FLYER_H

#include "flyobjects.h"


typedef enum {UP, DOWN, LEFT, RIGHT} CHECK_FLAG;

class flyer : public flyobjects
{
public:
    flyer(double,double,int,int,int,int,double,QWidget *);
    ~flyer();
    void paint();
    bool fall();
    void shoot();
    void move(QString);
    void wudi();
    void setsc(int);
    int optt(int);
private:
    int t;
};

#endif // FLYER_H
