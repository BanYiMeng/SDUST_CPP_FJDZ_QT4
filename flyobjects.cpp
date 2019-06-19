#include "flyobjects.h"

flyobjects::flyobjects(double xx=0,double yy=0,int ww=0,int hh=0,int tt=0,int cc=0,double pp=0):x(xx),y(yy),w(ww),h(hh),lt(tt),sc(cc),sp(pp),cx(xx+ww/2),cy(yy+hh/2),r(sqrt(ww*ww/4+hh*hh/4))
{

}
flyobjects::~flyobjects(){

}
