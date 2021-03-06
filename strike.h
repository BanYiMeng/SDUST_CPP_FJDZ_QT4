#ifndef STRIKE_H
#define STRIKE_H

#include <phonon>
#include "e_bullet.h"
#include "f_bullet.h"
#include "enemy.h"
#include "flyer.h"

class strike
{
public:
    strike(QList<enemy*> *,QList<e_bullet*> *,QList<f_bullet*> *,flyer *);
    int e2fb();
    void f2e();
    void f2eb();
    bool getflag();
    ~strike();
private:
    QList<enemy*> *el;
    QList<e_bullet*> *ebl;
    QList<f_bullet*> *fbl;
    flyer *f;
    bool flag;
    Phonon::AudioOutput *audioOutput;
    Phonon::MediaObject *mediaObject;

};

#endif // STRIKE_H
