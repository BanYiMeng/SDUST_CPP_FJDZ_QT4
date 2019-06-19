#ifndef FLYOBJECTS_H
#define FLYOBJECTS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QFrame>
#include <QPixmap>
#include <QPalette>
#include <QBitmap>
#include <math.h>

class flyobjects
{
public:
    flyobjects(double,double,int,int,int,int,double);
    virtual ~flyobjects();
    virtual void fall()=0;
    virtual void move(QString)=0;
    bool strike(flyobjects*,flyobjects*);
protected:
    int w,h,lt,sc,cx,cy;//lt=lifetime,sc=score,sp=speed
    double x,y,sp,r;
};

#endif // FLYOBJECTS_H
