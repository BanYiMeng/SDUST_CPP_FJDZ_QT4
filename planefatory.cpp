#include "planefatory.h"

planefatory::planefatory()
{

}

QList<enemy*>* planefatory::enemyfactory(int ww,int hh,double sp,QWidget *p){
    qlist.append(new enemy(0 ,0,ww,hh,0,0,sp,p));
    return &qlist;
}
