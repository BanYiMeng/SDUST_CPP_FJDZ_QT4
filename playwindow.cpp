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
    bf=new bulletfactory(this);
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
    delete ui;
    delete f;
    delete ref;
    delete pressedkeys;
    delete bga;
    delete bgb;
    delete bf;
    delete pf;
    delete im;
    delete mid;
    delete su;
    delete slow;
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
    emit exited(f->getsc());
}

void playwindow::endchoice()
{
    im->stop();
    ref->stop();
    mid->stop();
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
    if(pressedkeys->contains(Qt::Key_P)) {
       f->wudi();
    }

}

void playwindow::keytimer2()
{
    if(pressedkeys->contains(Qt::Key_H)) {
       bf->f_creator(f,f->optt(0));
    }
    ui->score->display(f->getsc());
    ui->hps->display(f->llt(0));
}

void playwindow::mids()
{
    el=pf->enemyfactory(f->getsc());
    bf->e_creator(el,f,0);
}

void playwindow::slows()
{
    su->creator();
}
