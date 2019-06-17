#include "playwindow.h"
#include "ui_playwindow.h"

playwindow::playwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playwindow)
{
    ui->setupUi(this);
    f=new flyer(0,0,0,0,0,0,0);
}

playwindow::~playwindow()
{
    delete ui;
}

void playwindow::keyPressEvent(QKeyEvent *ev){
    if(ev->key() == Qt::Key_W)
    {
        f->move("up");
    }
    if(ev->key() == Qt::Key_S)
    {
        f->move("down");
    }
    if(ev->key() == Qt::Key_A)
    {
        f->move("left");
    }
    if(ev->key() == Qt::Key_D)
    {
        f->move("right");
    }
    QWidget::keyPressEvent(ev);
}
void playwindow::keyReleaseEvent(QKeyEvent *ev){
    if(ev->key() == Qt::Key_W)
    {
    }
    if(ev->key() == Qt::Key_S)
    {
    }
    if(ev->key() == Qt::Key_A)
    {
    }
    if(ev->key() == Qt::Key_D)
    {
    }
    QWidget::keyReleaseEvent(ev);
}
