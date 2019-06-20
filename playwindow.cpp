#include "playwindow.h"
#include "ui_playwindow.h"

playwindow::playwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playwindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/resource/logo.jpg"));
    bg=new background(0,-800,600,1600,0,0,0,this,chapter::bgr(0));
    f=new flyer(270,649,60,82,100,0,0,this);
    f->show();
    bg->show();
    pressedkeys=new QString();
    connect(this,SIGNAL(ended()),this,SLOT(endchoice()));
    ref=new QTimer(this);
    ref->start(11);
    connect(ref,SIGNAL(timeout()),this,SLOT(again()));
    im=new QTimer(this);
    connect(im,SIGNAL(timeout()),this,SLOT(keytimer()));
}

playwindow::~playwindow()
{
    delete ui;
    delete f;
    delete ref;
    delete pressedkeys;
    delete bg;
}

void playwindow::keyPressEvent(QKeyEvent *ev){
    pressedkeys->append(static_cast<Qt::Key>(ev->key()));
    if(!im->isActive()) {
        im->start(11);
    }
}

void playwindow::keyReleaseEvent(QKeyEvent *ev){
    if(im->isActive() && pressedkeys->isEmpty()) {
           im->stop();
           keytimer();
       }
       pressedkeys->remove(static_cast<Qt::Key>(ev->key()));
}

void playwindow::closeEvent(QCloseEvent *event=0)
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
    /*if (flyobjects::strike(f,*))
    {
        if (*->sc<0)
            lt+=*->sc;
        else
            f=0;
    }*/
    bg->move();
    f->setmove();
}

void playwindow::keytimer(){
    if(pressedkeys->contains(Qt::Key_W)) {
        f->move("up");
    }
    if(pressedkeys->contains(Qt::Key_S)) {
        f->move("down");
    }
    if(pressedkeys->contains(Qt::Key_A)) {
        f->move("left");
    }
    if(pressedkeys->contains(Qt::Key_D)) {
        f->move("right");
    }
    if(pressedkeys->contains(Qt::Key_H)) {
       //shoot
    }
    if(pressedkeys->contains(Qt::Key_P)) {
       f->wudi();
    }
}
