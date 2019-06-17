#include "playwindow.h"
#include "ui_playwindow.h"

playwindow::playwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playwindow)
{
    ui->setupUi(this);
}

playwindow::~playwindow()
{
    delete ui;
}
