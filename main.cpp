#include "mainwindow.h"
#include "flyobject.h"
#include <QApplication>
#include <QWidget>
#include <QButtonGroup>
#include <QGraphicsDropShadowEffect>
#include <QtWebKit> //libqtwebkit-dev
#include <QUrl>

//#include <phonon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/resource/logo.jpg"));
    w.show();
    return a.exec();
}
