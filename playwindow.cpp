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
    ref=new QTimer(this);
    ref->start(11);
    connect(ref,SIGNAL(timeout()),this,SLOT(again()));
    im=new QTimer(this);
    connect(im,SIGNAL(timeout()),this,SLOT(keytimer()));
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
    pressedkeys.append(static_cast<Qt::Key>(ev->key()));
    if(!im->isActive()) {
        im->start(11);
    }
}

void playwindow::keyReleaseEvent(QKeyEvent *ev){
    if(im->isActive() && pressedkeys.isEmpty()) {
           im->stop();
           keytimer();
       }
       pressedkeys.remove(static_cast<Qt::Key>(ev->key()));
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

void playwindow::keytimer(){
    if(pressedkeys.contains(Qt::Key_W)) {
        f->move("up");
    }
    if(pressedkeys.contains(Qt::Key_S)) {
        f->move("down");
    }
    if(pressedkeys.contains(Qt::Key_A)) {
        f->move("left");
    }
    if(pressedkeys.contains(Qt::Key_D)) {
        f->move("right");
    }
    if(pressedkeys.contains(Qt::Key_H)) {
       //shoot
    }
}
