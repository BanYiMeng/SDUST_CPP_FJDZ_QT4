#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QKeyEvent>
#include <QMessageBox>
#include <QtCore>
#include "flyer.h"
#include "background.h"
#include "chapter.h"
#include "planefatory.h"
#include "bulletfactory.h"
#include "strike.h"
#include "supply.h"

namespace Ui {
class playwindow;
}

class playwindow : public QWidget
{
    Q_OBJECT

public:
    explicit playwindow(QWidget *parent = 0);
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

private:
    Ui::playwindow *ui;
    background *bga,*bgb;
    flyer *f;
    QTimer *ref,*im,*mid,*slow;
    void closeEvent(QCloseEvent *);
    QString *pressedkeys;
    planefatory *pf;
    bulletfactory *bf;
    strike *s;
    supply *su;
signals:
    void exited(int);
};

#endif // PLAYWINDOW_H
