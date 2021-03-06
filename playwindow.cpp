#include "playwindow.h"
#include "ui_playwindow.h"

playwindow::playwindow(QWidget *parent,int i,int x) :
    QWidget(parent),
    ui(new Ui::playwindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/resource/logo"));
    if (i<4&&i!=0)
    {
        wv=new QWebView(this);
        wv->move(-10,-10);
        wv->resize(620,820);
        wv->setWindowFlags(Qt::FramelessWindowHint);
        wv->load(chapter::vb(i));
        wv->showFullScreen();
    }
    wb+=x+i*101;
    lsc=x-i*10;
    bga=new background(0,0,600,800,0,0,0,this,chapter::bgr(i));
    bgb=new background(0,-800,600,800,0,0,0,this,chapter::bgr(i));
    f=new flyer(270,649,60,95,8,x,0,this);
    bo = new boss(0,-200,256,256,chapter::bhp(0),0,3,this,chapter::bpm(i));
    ui->bosss->setStyleSheet(chapter::bp(i));
    ui->bosss->raise();
    ui->bosshp->raise();
    ui->bosshp->setMaximum(10000);
    y=ui->bosss->y();
    yhp = ui->bosshp->y();
    bossflag=false;
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
    bos=new QTimer(this);
    pf=new planefatory(this);
    bf=new bulletfactory(pf->enemyfactory(-1),f,this);
    ui->scorelabel->raise();
    ui->score->raise();
    ui->hplabel->raise();
    ui->hps->raise();
    s=new strike(pf->getel(),bf->getebl(),bf->getfbl(),f);
    su=new supply(-50,-50,60,60,0,0,2,this,f);
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory);
    mediaObject = new Phonon::MediaObject;
    Phonon::createPath(mediaObject, audioOutput);
    mediaObject->setCurrentSource(chapter::mr(i));
    mediaObject->play();
    connect(mediaObject,SIGNAL(finished()),this,SLOT(replay()));
    connect(slow,SIGNAL(timeout()),this,SLOT(slows()));
    connect(ref,SIGNAL(timeout()),this,SLOT(again()));
    connect(ref,SIGNAL(timeout()),this,SLOT(keytimer()));
    connect(im,SIGNAL(timeout()),this,SLOT(keytimer2()));
    connect(mid,SIGNAL(timeout()),this,SLOT(mids()));
    connect(bos,SIGNAL(timeout()),this,SLOT(bbos()));
}

playwindow::~playwindow()
{
    ref->deleteLater();
    im->deleteLater();
    mid->deleteLater();
    slow->deleteLater();
    bos->deleteLater();
    mediaObject->deleteLater();
    audioOutput->deleteLater();
    delete pressedkeys;
    delete bga;
    delete bgb;
    delete s;
    delete bf;
    delete pf;
    delete su;
    delete bo;
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
            if (bossflag==false)
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
    bos->stop();
    emit exited(f->getsc());
    setWindowTitle("stopping...");
    QEventLoop loop;
    QTimer::singleShot(501, &loop, SLOT(quit()));
    loop.exec();

}

void playwindow::endchoice()
{
    im->stop();
    ref->stop();
    mid->stop();
    slow->stop();
    bos->stop();
    QString qs="yours score is:";
    qs.append(QString::number(f->getsc(),10));
    QMessageBox::about(NULL,"Laji!",qs);
    if(QMessageBox::Ok){
        close();
    }
}

void playwindow::gameover(){
    im->stop();
    ref->stop();
    mid->stop();
    slow->stop();
    bos->stop();
    QMessageBox::about(NULL,"NiuBi","Congratulations!");
    emit pass(f->getsc());
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
    if(bossflag==true){
        if(y<=0){
            ui->bosss->move(520,++y);
            ui->bosshp->move(520,++yhp);
        }
        bo->move();
        if(bo->strike(bf->getfbl()))
        {
            bo->fall();
            gameover();
        }
    }
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
    if(f->getsc()>=wb&&bossflag==false){
        showboss();
        bossflag=true;
    }
    bf->e_creator(0);
    pf->enemyfactory(f->getsc()-lsc);
}

void playwindow::slows()
{
    su->creator();
}

void playwindow::showboss(){
    bo->show();
    ui->bosss->show();
    mid->stop();
    mid->start(20001);
    bos->start(1111);
}

void playwindow::bbos(){
     bo->shoot(bf->getebl());
     ui->bosshp->setValue(bo->llt(0));
}

void playwindow::replay()
{
    mediaObject->play();
}
