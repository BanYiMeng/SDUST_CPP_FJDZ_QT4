#include "mainwindow.h"
#include <QApplication>

//#include <phonon>

int main(int argc, char *argv[])
{
    QApplication *p =new QApplication(argc, argv);
    if(!p)
        return -1;
    MainWindow w;
    w.setWindowIcon(QIcon(":/resource/logo"));
    w.show();
    int ret;
    ret = p->exec();
    p->exit(1);
    return ret;
}
