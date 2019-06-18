#include "playwindow.h"
#include "ui_playwindow.h"

playwindow::playwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playwindow)
{
    ui->setupUi(this);
    f=new flyer(1,1,0,0,0,0,0);
    connect(this,SIGNAL(ended()),this,SLOT(endchoice()));
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
    if(ev->key() == Qt::Key_Escape)
    {
        emit ended();
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

void playwindow::closeEvent(QCloseEvent *event)
{
    emit exited();
}

void playwindow::endchoice()
{
    QMessageBox::StandardButton ans=QMessageBox::warning(NULL,QString::fromUtf8("警告"),QString::fromUtf8("是否退出游戏"),QMessageBox::Yes | QMessageBox::No,QMessageBox::No);
    if(ans == QMessageBox::Yes)
    {
        close();
    }
}
