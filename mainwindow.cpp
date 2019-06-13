#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QtWebKit>
#include <QUrl>
#include <QWidget>
#include <QMessageBox>
#include <QtCore>

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
    mp->load(QUrl("https://test-1254946716.cos.ap-chongqing.myqcloud.com/main-bgm.mp3"));
    connect(ui->Cg,SIGNAL(clicked()),this,SLOT(on_Cg_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Cg_clicked()
{
    if (cg==false)
    {
    delete mp;
    cg=true;
    wv=new QWebView;
    wv->setAttribute(Qt::WA_DeleteOnClose);
    wv->load(QUrl("https://test-1254946716.cos.ap-chongqing.myqcloud.com/cg.mp4"));
    wv->showFullScreen();
    end=new QTimer(this);
    end->start(210001);
    connect(end,SIGNAL(timeout()),this,SLOT(generic()));
    }
}

void MainWindow::generic()
{
    delete wv;
    delete end;
    mp=new QWebView;
    mp->load(QUrl("https://test-1254946716.cos.ap-chongqing.myqcloud.com/main-bgm.mp3"));
    cg=false;
}
