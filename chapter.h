#ifndef CHAPTER_H
#define CHAPTER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QUrl>

class chapter
{
public:
    chapter();
    static QString bgr(int);
    static QUrl mr(int);
    static QString bp(int);
    static QString bpm(int);
private:
};

#endif // CHAPTER_H
