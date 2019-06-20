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
    flyobjects(double,double,int,int,int,int,double,QWidget *);
    virtual ~flyobjects();
    virtual void fall()=0;
    void setmove();
    static bool strike(flyobjects *,flyobjects *);
    void show();
protected:
    int w,h,lt,sc,cx,cy;//lt=lifetime,sc=score,sp=speed
    double x,y,sp,r;
    QPixmap *pix;
    QFrame *frame;
};

#endif // FLYOBJECTS_H
