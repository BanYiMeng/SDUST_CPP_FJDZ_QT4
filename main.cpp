#include "mainwindow.h"
#include <QApplication>
#include <QWidget>

//#include <phonon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/resource/logo.jpg"));
    w.show();
    return a.exec();
}
