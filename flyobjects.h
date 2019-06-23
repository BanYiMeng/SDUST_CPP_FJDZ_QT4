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
    void setmove();
    void show();
    double getcx();
    double getcy();
    void setsp(int);
    double getsp();
    int getr();
    int llt(int);
    int getsc();
protected:
    int w,h,lt,sc,r;//lt=lifetime,sc=score,sp=speed
    double x,y,sp,cx,cy;
    QPixmap *pix;
    QFrame *frame;
};

#endif // FLYOBJECTS_H
