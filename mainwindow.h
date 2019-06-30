#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsDropShadowEffect>
#include <QtWebKit>
#include <phonon>
#include "playwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Cg_clicked();

    void Exit_Cg();

    void on_About_clicked();

    void on_Starter_clicked();

    void Reboot(int);

    void passed(int);

private:
    Ui::MainWindow *ui;
    bool duo=true;
    QWebView *wv=NULL;
    QTimer *end=NULL;
    playwindow *p;
    QFile *sf;
    QFile *csf;
    QTextStream *txtInput;
    QTextStream *ctxtInput;
    Phonon::AudioOutput *audioOutput;
    Phonon::MediaObject *mediaObject;
    int hest=-1;
    int ch=0;
    int sc=0;
};

#endif // MAINWINDOW_H
