#include "chapter.h"

chapter::chapter()
{

}

QString chapter::bgr(int i=0)
{
    if (i==0)
        return QString(":/resource/playbackground");
    else if (i==1)
        return QString(":/resource/-1.png");
    else if (i==2)
        return QString(":/resource/-1.png");
    else if (i==3)
        return QString(":/resource/-1.png");
    else
        return QString(":/resource/playbackground");
}

QUrl chapter::mr(int i=0)
{
    if (i==0)
        return QUrl::fromLocalFile("/home/tester/resource/b1.mp3");
    else if (i==1)
        return QUrl::fromLocalFile("/home/tester/resource/b2.mp3");
    else if (i==2)
        return QUrl::fromLocalFile("/home/tester/resource/b3.mp3");
    else if (i==3)
        return QUrl::fromLocalFile("/home/tester/resource/b4.mp3");
    else
        return QUrl::fromLocalFile("/home/tester/resource/b5.mp3");
}

QString chapter::bp(int i=0)
{
    if (i==0)
        return QString("QPushButton{border-image:url(:/resource/boss_l1.png);}");
    else if (i==1)
        return QString("QPushButton{border-image:url(:/resource/boss_l2.png);}");
    else if (i==2)
        return QString("QPushButton{border-image:url(:/resource/boss_l3.png);}");
    else if (i==3)
        return QString("QPushButton{border-image:url(:/resource/boss_l4.png);}");
    else
        return QString("QPushButton{border-image:url(:/resource/boss_l1.png);}");
}

QString chapter::bpm(int i=0)
{
    if (i==0)
        return QString(":/resource/boss_l1_mod");
    else if (i==1)
        return QString(":/resource/boss_l2_mod");
    else if (i==2)
        return QString(":/resource/boss_l3_mod");
    else if (i==3)
        return QString(":/resource/boss_l4_mod");
    else
        return QString(":/resource/boss_l1_mod");
}

int chapter::bhp(int i=0)
{
    if (i==0)
        return 10000;
    else if (i==1)
        return 12500;
    else if (i==2)
        return 15000;
    else if (i==3)
        return 20000;
    else
        return 10000;
}

QUrl chapter::vb(int i=0)
{
    if (i==1)
        return QUrl::fromLocalFile("/home/tester/resource/c1.html");
    else if (i==2)
        return QUrl::fromLocalFile("/home/tester/resource/c2.html");
    else if (i==3)
        return QUrl::fromLocalFile("/home/tester/resource/c3.html");
}
