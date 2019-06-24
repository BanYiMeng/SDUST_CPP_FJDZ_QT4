#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QKeyEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QtCore>
#include <QKeySequence>
#include <QMessageBox>
#include "flyer.h"
#include "background.h"
#include "chapter.h"
#include "planefatory.h"
#include "bulletfactory.h"
#include "strike.h"

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

private:
    Ui::playwindow *ui;
    background *bga,*bgb;
    flyer *f;
    QTimer *ref,*im,*mid;
    void closeEvent(QCloseEvent *);
    QString *pressedkeys;
    planefatory *pf;
    bulletfactory *bf;
    QList<enemy*> *el;
    strike *s;
signals:
    void exited();
    void ended();
};

#endif // PLAYWINDOW_H
