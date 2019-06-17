#ifndef FLYOBJECTS_H
#define FLYOBJECTS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>

class flyobjects
{
public:
    flyobjects(int,int,int,int,int,int,int);
    ~flyobjects();
    virtual void fall()=0;
    virtual void move(QString)=0;
protected:
    int x,y,w,h,lt,sc,sp;//lt=lifetime,sc=score,sp=speed
};

#endif // FLYOBJECTS_H
