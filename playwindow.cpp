#include "playwindow.h"
#include "ui_playwindow.h"

playwindow::playwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playwindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/resource/logo"));
    bga=new background(0,0,600,800,0,0,0,this,chapter::bgr(0));
    bgb=new background(0,-800,600,800,0,0,0,this,chapter::bgr(0));
    f=new flyer(270,649,60,82,100,0,0,this);
    f->show();
    bga->show();
    bgb->show();
    ui->player->raise();
    pressedkeys=new QString();
    ref=new QTimer(this);
    ref->start(11);
    im=new QTimer(this);
    im->start(111);
    mid=new QTimer(this);
    mid->start(1111);
    pf=new planefatory(this);
    bf=new bulletfactory(this);
    s=new strike(pf->getel(),bf->getebl(),bf->getfbl(),f);
    connect(this,SIGNAL(ended()),this,SLOT(endchoice()));
    connect(ref,SIGNAL(timeout()),this,SLOT(again()));
    connect(ref,SIGNAL(timeout()),this,SLOT(keytimer()));
    connect(im,SIGNAL(timeout()),this,SLOT(keytimer2()));
    connect(mid,SIGNAL(timeout()),this,SLOT(mids()));
}

playwindow::~playwindow()
{
    delete ui;
    delete f;
    delete ref;
    delete pressedkeys;
    delete bga;
    delete bgb;
    delete pf;
    delete bf;
    delete im;
    delete mid;
}

void playwindow::keyPressEvent(QKeyEvent *ev){
    pressedkeys->append(static_cast<Qt::Key>(ev->key()));
}

void playwindow::keyReleaseEvent(QKeyEvent *ev){
    if (ev->key() == Qt::Key_W)
        f->setsp(0);
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
    f->setsc(s->e2fb());
    bf->moves();
    pf->moves();
    bga->move();
    bgb->move();
    f->setmove();
}

void playwindow::keytimer(){
    if(pressedkeys->contains(Qt::Key_W)) {
        f->move("up");
        f->setsp(3);
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
    if(pressedkeys->contains(Qt::Key_P)) {
       f->wudi();
    }

}

void playwindow::keytimer2()
{
    if(pressedkeys->contains(Qt::Key_H)) {
       bf->f_creator(f,1);
    }
}

void playwindow::mids()
{
    el=pf->enemyfactory(f->getsc());
    bf->e_creator(el,f,0);
}
