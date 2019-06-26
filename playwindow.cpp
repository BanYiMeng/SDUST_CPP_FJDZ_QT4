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
    f=new flyer(270,649,60,82,8,0,0,this);
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
    slow=new QTimer(this);
    slow->start(60001);
    pf=new planefatory(this);
    bf=new bulletfactory(pf->enemyfactory(-1),f,this);
    ui->scorelabel->raise();
    ui->score->raise();
    ui->hplabel->raise();
    ui->hps->raise();
    s=new strike(pf->getel(),bf->getebl(),bf->getfbl(),f);
    su=new supply(-50,-50,60,60,0,0,2,this,f);
    connect(slow,SIGNAL(timeout()),this,SLOT(slows()));
    connect(ref,SIGNAL(timeout()),this,SLOT(again()));
    connect(ref,SIGNAL(timeout()),this,SLOT(keytimer()));
    connect(im,SIGNAL(timeout()),this,SLOT(keytimer2()));
    connect(mid,SIGNAL(timeout()),this,SLOT(mids()));
}

playwindow::~playwindow()
{
    setWindowTitle("stopping...");
    ref->deleteLater();
    im->deleteLater();
    mid->deleteLater();
    slow->deleteLater();
    delete pressedkeys;
    delete bga;
    delete bgb;
    delete bf;
    delete pf;
    delete su;
    delete f;
    delete ui;
}

void playwindow::keyPressEvent(QKeyEvent *ev){
    if(ev->key() == Qt::Key_P)
        f->wudi();
    else if(ev->key() == Qt::Key_L)
    {
        if (f->llt(0)==-1)
            f->llt(9);
    }
    pressedkeys->append(static_cast<Qt::Key>(ev->key()));
}

void playwindow::keyReleaseEvent(QKeyEvent *ev){
    if (ev->key() == Qt::Key_W)
    {
        pressedkeys->remove(static_cast<Qt::Key>(ev->key()));
        f->setsp(0);
    }
    else if (ev->key() == Qt::Key_Escape)
    {
        pressedkeys->remove(static_cast<Qt::Key>(ev->key()));
        im->stop();
        ref->stop();
        mid->stop();
        slow->stop();
        QMessageBox::StandardButton mb = QMessageBox::question(NULL,QString::fromUtf8("游戏已冻结"),QString::fromUtf8("是否返回主界面?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if (mb == QMessageBox::Yes)
            close();
        else
        {
            ref->start(11);
            im->start(111);
            mid->start(1111);
            slow->start(60001);
        }
    }
    else
        pressedkeys->remove(static_cast<Qt::Key>(ev->key()));
}

void playwindow::closeEvent(QCloseEvent *event=0)
{
    im->stop();
    ref->stop();
    mid->stop();
    slow->stop();
    emit exited(f->getsc());
}

void playwindow::endchoice()
{
    im->stop();
    ref->stop();
    mid->stop();
    slow->stop();
    QString qs="yours score is:";
    qs.append(QString::number(f->getsc(),10));
    QMessageBox::about(NULL,"Laji!",qs);
    if(QMessageBox::Ok){
        close();
    }
}

void playwindow::again()
{
    f->setsc(s->e2fb());
    su->update();
    su->move();
    s->f2e();
    s->f2eb();
    bf->moves();
    pf->moves();
    bga->move();
    bgb->move();
    f->setmove();
    if(s->getflag())
        endchoice();
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
}

void playwindow::keytimer2()
{
    if(pressedkeys->contains(Qt::Key_H)) {
       bf->f_creator(f->optt(0));
    }
    ui->score->display(f->getsc());
    ui->hps->display(f->llt(0));
}

void playwindow::mids()
{
    bf->e_creator(0);
     pf->enemyfactory(f->getsc());
}

void playwindow::slows()
{
    su->creator();
}
