#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/resource/logo.jpg"));
    w.setStyleSheet("border-image:url(:/resource/background.jpg);");
    w.show();

    return a.exec();
}
//warn
