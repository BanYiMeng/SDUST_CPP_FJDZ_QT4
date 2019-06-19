#include "playwindow.h"
#include "ui_playwindow.h"

playwindow::playwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playwindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/resource/logo.jpg"));
    f=new flyer(270,649,60,82,3,0,0,this);
    f->show();
    connect(this,SIGNAL(ended()),this,SLOT(endchoice()));
    ref=new QTimer();
    ref->start(19);
    connect(ref,SIGNAL(timeout()),this,SLOT(again()));
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/resource/playbackground.jpg")));//playwindow background
    setPalette(pal);
}

playwindow::~playwindow()
{
    delete ui;
    delete f;
    delete ref;
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
    QMessageBox::StandardButton ans=QMessageBox::warning(NULL,QString::fromUtf8("警告"),QString::fromUtf8("是否退出对局"),QMessageBox::Yes | QMessageBox::No,QMessageBox::No);
    if(ans == QMessageBox::Yes)
    {
        close();
    }
}

void playwindow::again()
{
    f->setmove();
}
