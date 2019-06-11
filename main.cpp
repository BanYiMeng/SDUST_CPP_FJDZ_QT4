#include "mainwindow.h"
#include <QApplication>
//#include <phonon>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/resource/logo.jpg"));
    w.setStyleSheet("border-image:url(:/resource/background.jpg);");
    //Phonon::VideoPlayer *player =new Phonon::VideoPlayer(Phonon::VideoCategory,&w);
    //player->resize(800,450);
    //player->load(Phonon::MediaSource("/home/tester/文档/extra/video.mp4"));
    //player->play();
    w.show();
    return a.exec();
}
//warn
