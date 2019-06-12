#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QButtonGroup>
#include <QGraphicsDropShadowEffect>
//#include <QtWebKit>
//#include <QUrl>

//#include <phonon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/resource/logo.jpg"));
    w.show();
    return a.exec();
}
//warn
