#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <flyobjects.h>

class background : public flyobjects
{
public:
    background(double,double,int,int,int,int,double,QWidget *,QString);
    void fall();
    void move();
};

#endif // BACKGROUND_H
