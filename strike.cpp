#include "strike.h"

strike::strike(QList<enemy*> *e,QList<e_bullet*> *eb,QList<f_bullet*> *fb,flyer *ff):el(e),ebl(eb),fbl(fb),f(ff)
{

}

int strike::e2fb()
{
    int t=0;
    for (int i=0;i<el->length();i++)
    {
        for (int k=0;k<fbl->length();k++)
        {
            if ((el->at(i)->getr()+fbl->at(k)->getr())*(el->at(i)->getr()+fbl->at(k)->getr())>(el->at(i)->getcx()-fbl->at(k)->getcx())*(el->at(i)->getcx()-fbl->at(k)->getcx())+(el->at(i)->getcy()-fbl->at(k)->getcy())*(el->at(i)->getcy()-fbl->at(k)->getcy()))
            {
                if (el->at(i)->llt(fbl->at(k)->llt(0))<=0)
                {
                    t+=el->at(i)->getsc();
                    delete el->operator [](i);
                    delete fbl->operator [](k);
                    el->removeAt(i);
                    fbl->removeAt(k);
                }
                else
                {
                   delete fbl->operator [](k);
                   fbl->removeAt(k);
                }
                if (k>0)
                    k--;
                if (i>0)
                    i--;
                if (!el->length()||!fbl->length())
                    return t;
            }
        }
    }
    return t;
}
