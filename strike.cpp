#include "strike.h"

strike::strike(QList<enemy*> *e,QList<e_bullet*> *eb,QList<f_bullet*> *fb,flyer *ff):el(e),ebl(eb),fbl(fb),f(ff),flag(false)
{
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory);
    mediaObject = new Phonon::MediaObject;
    Phonon::createPath(mediaObject, audioOutput);
    mediaObject->setCurrentSource(QUrl("/home/tester/resource/shot.mp3"));
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
                    mediaObject->play();
                    t+=el->at(i)->getsc();
                    el->at(i)->fall();
                    fbl->at(k)->fall();
                    el->removeAt(i);
                    fbl->removeAt(k);
                    k=-1;
                    if (i>0)
                        i--;
                }
                else
                {
                   fbl->at(k)->fall();
                   fbl->removeAt(k);
                   if (k>=0)
                       k--;
                }
                if (!el->length()||!fbl->length())
                    return t;
            }
        }
    }
    return t;
}

void strike::f2e(){
    for(int i=0;i<el->length();i++){
        if ((f->getr()+el->at(i)->getr())*(f->getr()+el->at(i)->getr())>(f->getcx()-el->at(i)->getcx())*(f->getcx()-el->at(i)->getcx())+(f->getcy()-el->at(i)->getcy())*(f->getcy()-el->at(i)->getcy())){
            if(f->llt(0)>0)
            {
                if (f->llt(-el->at(i)->llt(0))<=0){
                    flag=true;
                }
            }
            el->at(i)->fall();
            el->removeAt(i);
            if (i>0)
                i--;
        }
    }
}


void strike::f2eb(){
    for(int i=0;i<ebl->length();i++){
        if ((f->getr()+ebl->at(i)->getr())*(f->getr()+ebl->at(i)->getr())>(f->getcx()-ebl->at(i)->getcx())*(f->getcx()-ebl->at(i)->getcx())+(f->getcy()-ebl->at(i)->getcy())*(f->getcy()-ebl->at(i)->getcy())){
            if(f->llt(0)>0)
            {
                if (f->llt(ebl->at(i)->llt(0))<=0){
                    flag=true;
                }
            }
            ebl->at(i)->fall();
            ebl->removeAt(i);
            if (i>0)
                i--;
        }
    }
}

bool strike::getflag(){
    return flag;
}

strike::~strike()
{
    mediaObject->deleteLater();
    audioOutput->deleteLater();
}
