#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebView>
#include <QtCore>

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

private:
    Ui::MainWindow *ui;
    bool duo=false;
    QWebView *wv;
    QWebView *mp;
    QTimer *end;
};

#endif // MAINWINDOW_H
