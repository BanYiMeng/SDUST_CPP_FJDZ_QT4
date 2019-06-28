#include "special.h"

special::special()
{

}

QString special::boom(int i=0)
{
    if (i==1)
        return QString(":/resource/enemy_l1_b");
    else if (i==3)
        return QString(":/resource/enemy_l2_b");
    else if (i==5)
        return QString(":/resource/enemy_l3_b");
    else
        return QString(":/resource/enemy_l1_b");
}

int special::boom_T(int i=0)
{
    if (i==1)
        return 401;
    else if (i==3)
        return 481;
    else if (i==5)
        return 541;
    else
        return 401;
}
