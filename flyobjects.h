#ifndef FLYOBJECTS_H
#define FLYOBJECTS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class flyobjects
{
public:
    flyobjects();
private:
    int x,y,w,h,lt,sc,sp;//lt=lifetime,sc=score,sp=speed
};

#endif // FLYOBJECTS_H
