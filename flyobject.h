#ifndef FLYOBJECT_H
#define FLYOBJECT_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>

class flyobjectData;

class flyobject
{
public:
    flyobject(int xx=-1,int yy=-1,int ss=-1,int tt=-1,int ww=-1,int hh=-1):x(xx),y(yy),s(ss),t(tt),w(ww),h(hh){
    };//x,y,s:speed,t:times,w:weight.h:hight;
    flyobject(const flyobject &);
    flyobject &operator=(const flyobject &);
    ~flyobject();
private:
    int x,y,s,t,w,h;
    QSharedDataPointer<flyobjectData> data;
};

#endif // FLYOBJECT_H
