#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor(QColor(0,0,0));
    shadowEffect->setBlurRadius(10);
    ui->pushButton->setGraphicsEffect(shadowEffect);
}

MainWindow::~MainWindow()
{
    delete ui;
}
