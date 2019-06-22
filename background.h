#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <flyobjects.h>

class background : public flyobjects
{
public:
    background(double,double,int,int,int,int,double,QWidget *,const QString &);
    void move();
};

#endif // BACKGROUND_H
