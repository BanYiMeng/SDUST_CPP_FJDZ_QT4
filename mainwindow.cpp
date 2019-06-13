#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QtWebKit>
#include <QUrl>
#include <QWidget>
#include <QMessageBox>

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
    connect(ui->Cg,SIGNAL(clicked()),this,SLOT(on_Cg_clicked()));
    cg=false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Cg_clicked()
{
    if (cg==false)
    {
    cg=true;
    QWebView *wv=new QWebView;
    wv->setAttribute(Qt::WA_DeleteOnClose);
    wv->load(QUrl("https://test-1254946716.cos.ap-chongqing.myqcloud.com/cg.mp4"));
    wv->showMaximized();
    }
}
