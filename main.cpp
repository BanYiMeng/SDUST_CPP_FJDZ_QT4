#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QtWebKit>
#include <QUrl>

//#include <phonon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/resource/logo.jpg"));
    w.setStyleSheet("border-image:url(:/resource/background.jpg);");
    QWebView wv;
    wv.setAttribute(Qt::WA_DeleteOnClose);
    wv.load(QUrl("https://test-1254946716.cos.ap-chongqing.myqcloud.com/video.mp4"));
    wv.showFullScreen();
    //Phonon::VideoPlayer *player =new Phonon::VideoPlayer(Phonon::VideoCategory,&w);
    //player->resize(800,450);
    //player->load(Phonon::MediaSource("/home/tester/文档/extra/video.mp4"));
    //player->play();
    w.show();
    return a.exec();
}
//warn
