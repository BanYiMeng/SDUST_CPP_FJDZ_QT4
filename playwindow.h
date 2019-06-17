#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QWidget>

namespace Ui {
class playwindow;
}

class playwindow : public QWidget
{
    Q_OBJECT

public:
    explicit playwindow(QWidget *parent = 0);
    ~playwindow();

private:
    Ui::playwindow *ui;
};

#endif // PLAYWINDOW_H
