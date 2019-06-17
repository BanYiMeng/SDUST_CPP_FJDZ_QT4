#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QtWebKit>
#include <QUrl>
#include <QWidget>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor(QColor(0,0,0));
    shadowEffect->setBlurRadius(10);
    ui->Starter->setGraphicsEffect(shadowEffect);
    ui->Cg->setGraphicsEffect(shadowEffect);
    mp=new QWebView;
    p=new playwindow;
    mp->load(QUrl("https://test-1254946716.cos.ap-chongqing.myqcloud.com/main-bgm.mp3"));
    connect(ui->Cg,SIGNAL(clicked()),this,SLOT(on_Cg_clicked()));
    connect(ui->About,SIGNAL(clicked()),this,SLOT(on_About_clicked()));
    connect(ui->Starter,SIGNAL(clicked()),this,SLOT(on_Starter_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Cg_clicked()
{
    if (duo==false)
    {
    delete mp;
    duo=true;
    wv=new QWebView;
    wv->setAttribute(Qt::WA_DeleteOnClose);
    wv->load(QUrl("https://test-1254946716.cos.ap-chongqing.myqcloud.com/cg.mp4"));
    wv->showFullScreen();
    end=new QTimer(this);
    end->start(210001);
    connect(end,SIGNAL(timeout()),this,SLOT(Exit_Cg()));
    }
}

void MainWindow::Exit_Cg()
{
    delete wv;
    delete end;
    mp=new QWebView;
    mp->load(QUrl("https://test-1254946716.cos.ap-chongqing.myqcloud.com/main-bgm.mp3"));
    duo=false;
}

void MainWindow::on_About_clicked()
{
    if (duo==false)
    {
    duo=true;
    QMessageBox::about(NULL,QString::fromUtf8("关于"),QString::fromUtf8("制作:奚浩然,王崇霖,颜伯同"));
    end=new QTimer(this);
    end->start(1001);
    connect(end,SIGNAL(timeout()),this,SLOT(Exit_About()));
    }
}

void MainWindow::Exit_About()
{
    delete end;
    duo=false;
}

void MainWindow::on_Starter_clicked()
{
    if (duo==false)
    {
    duo=true;
    MainWindow::close();
    p->show();
    end=new QTimer(this);
    end->start(1001);
    connect(end,SIGNAL(timeout()),this,SLOT(Exit_Game()));
    }
}

void MainWindow::Exit_Game()
{
    delete end;
    duo=false;
}
