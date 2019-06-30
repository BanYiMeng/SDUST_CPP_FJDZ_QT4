#ifndef FLYER_H
#define FLYER_H

#include <QTimer>
#include "flyobjects.h"


typedef enum {UP, DOWN, LEFT, RIGHT} CHECK_FLAG;

class flyer : public flyobjects
{
    Q_OBJECT

public:
    flyer(double,double,int,int,int,int,double,QWidget *);
    ~flyer();
    void paint();
    void shoot();
    void move(QString);
    void wudi();
    void setsc(int);
    int optt(int);
private:
    int t;
    int backup;
private slots:
    void changet();
};

#endif // FLYER_H
