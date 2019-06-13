#include "mainwindow.h"
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
    QWebView mp;
    mp.load(QUrl("https://test-1254946716.cos.ap-chongqing.myqcloud.com/main-bgm.mp3"));
    return a.exec();
}
//warn
