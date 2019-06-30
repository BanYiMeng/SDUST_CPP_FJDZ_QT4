#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose);
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor(QColor(0,0,0));
    shadowEffect->setBlurRadius(10);
    ui->Starter->setGraphicsEffect(shadowEffect);
    ui->Cg->setGraphicsEffect(shadowEffect);
    ui->About->setGraphicsEffect(shadowEffect);
    ui->hint->setGraphicsEffect(shadowEffect);
    ui->scores->setGraphicsEffect(shadowEffect);
    ui->scorelabel->setGraphicsEffect(shadowEffect);
    ui->scores2->setGraphicsEffect(shadowEffect);
    ui->scorelabel2->setGraphicsEffect(shadowEffect);
    sf=new QFile("./best_score");
    sf->open(QIODevice::ReadOnly | QIODevice::Text);
    txtInput=new QTextStream(sf);
    hest=txtInput->readLine().toInt();
    ui->scores->display(hest);
    csf=new QFile("./c_score");
    csf->open(QIODevice::ReadOnly | QIODevice::Text);
    ctxtInput=new QTextStream(csf);
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory);
    mediaObject = new Phonon::MediaObject;
    Phonon::createPath(mediaObject, audioOutput);
    mediaObject->setCurrentSource(QUrl("/home/tester/resource/main-bgm.mp3"));
    mediaObject->play();
    connect(ui->Cg,SIGNAL(clicked()),this,SLOT(on_Cg_clicked()));
    connect(ui->About,SIGNAL(clicked()),this,SLOT(on_About_clicked()));
    connect(ui->Starter,SIGNAL(clicked()),this,SLOT(on_Starter_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sf;
    delete txtInput;
    delete csf;
    delete ctxtInput;
    delete audioOutput;
    delete mediaObject;
}

void MainWindow::on_Cg_clicked()
{
    if (duo==false)
    {
        mediaObject->stop();
        duo=true;
        wv=new QWebView;
        wv->setAttribute(Qt::WA_DeleteOnClose);
        wv->load(QUrl::fromLocalFile("/home/tester/resource/cg.html"));
        wv->showFullScreen();
        if (end==NULL)
            end=new QTimer(this);
        end->start(210001);
        connect(end,SIGNAL(timeout()),this,SLOT(Exit_Cg()));
    }
    else
        duo=false;
}

void MainWindow::Exit_Cg()
{
    if (wv!=NULL)
    {
        delete wv;
        wv=NULL;
    }
    delete end;
    end=NULL;
    mediaObject->play();
}

void MainWindow::on_About_clicked()
{
    if (duo == false)
    {
    duo=true;
    QMessageBox::about(NULL,QString::fromUtf8("关于"),QString::fromUtf8("制作:奚浩然,王崇霖,颜伯同"));
    }
    else
        duo=false;
}

void MainWindow::on_Starter_clicked()
{
    if (duo == false)
    {
    duo=true;
    MainWindow::close();
    mediaObject->stop();
    p=new playwindow(0,ch,sc);
    p->setAttribute(Qt::WA_DeleteOnClose);
    p->show();
    connect(p,SIGNAL(exited(int)),this,SLOT(Reboot(int)));
    connect(p,SIGNAL(pass(int)),this,SLOT(passed(int)));
    }
    else
        duo=false;
}

void MainWindow::Reboot(int i=0)
{
    if (i>hest)
    {
        freopen("./best_score","w",stdout);
        printf("%d",i);
        ui->scores->display(i);
        fclose(stdout);
        hest=i;
    }
    ui->scores2->display(i);
    freopen("./c_score","w",stdout);
    printf("%d",i);
    fclose(stdout);
    mediaObject->play();
    this->show();
}

void MainWindow::passed(int i=0)
{
    sc=i;
    ch++;
}
