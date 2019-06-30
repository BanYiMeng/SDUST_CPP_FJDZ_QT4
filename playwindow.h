#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QKeyEvent>
#include <QMessageBox>
#include <QtCore>
#include <QtWebKit>
#include <phonon>
#include "flyer.h"
#include "background.h"
#include "chapter.h"
#include "planefatory.h"
#include "bulletfactory.h"
#include "strike.h"
#include "supply.h"
#include "boss.h"

namespace Ui {
class playwindow;
}

class playwindow : public QWidget
{
    Q_OBJECT

public:
    explicit playwindow(QWidget *parent,int,int);
    ~playwindow();
    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);

private slots:
    void endchoice();

    void again();

    void keytimer();

    void keytimer2();

    void mids();

    void slows();

    void gameover();

    void showboss();

    void bbos();

    void replay();
private:
    Ui::playwindow *ui;
    background *bga,*bgb;
    flyer *f;
    QTimer *ref,*im,*mid,*slow,*bos;
    void closeEvent(QCloseEvent *);
    QString *pressedkeys;
    planefatory *pf;
    bulletfactory *bf;
    strike *s;
    supply *su;
    boss *bo;
    bool bossflag;
    int y;
    int yhp;
    QWebView *wv=NULL;
    int wb=31;
    int lsc=0;
    Phonon::AudioOutput *audioOutput;
    Phonon::MediaObject *mediaObject;
signals:
    void exited(int);
    void pass(int);
};

#endif // PLAYWINDOW_H
