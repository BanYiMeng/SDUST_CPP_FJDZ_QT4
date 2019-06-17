#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include "flyer.h"

namespace Ui {
class playwindow;
}

class playwindow : public QWidget
{
    Q_OBJECT

public:
    explicit playwindow(QWidget *parent = 0);
    ~playwindow();
    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);
private:
    Ui::playwindow *ui;
    flyer *f;
};

#endif // PLAYWINDOW_H
