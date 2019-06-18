#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QGraphicsDropShadowEffect>
#include <QtWebKit>
#include <QUrl>
#include <QString>
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

    void Exit_About();

    void on_Starter_clicked();

    void Exit_Game();
    void Reboot();

private:
    Ui::MainWindow *ui;
    bool duo=false;
    QWebView *wv;
    QWebView *mp;
    QTimer *end;
    playwindow *p;
};

#endif // MAINWINDOW_H
