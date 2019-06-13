#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebView>

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

    void generic ();

private:
    Ui::MainWindow *ui;
    bool cg=false;
    QWebView *wv;
    QWebView *mp;
};

#endif // MAINWINDOW_H
