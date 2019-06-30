#include "chapter.h"

chapter::chapter()
{

}

QString chapter::bgr(int i=0)
{
    if (i==0)
        return QString(":/resource/playbackground");
    else if (i==1)
        return QString("");
    else if (i==2)
        return QString("");
    else if (i==3)
        return QString("");
    else
        return QString(":/resource/playbackground");
}

QUrl chapter::mr(int i=0)
{
    if (i==0)
        return QUrl();
    else if (i==1)
        return QUrl();
    else if (i==2)
        return QUrl();
    else if (i==3)
        return QUrl();
    else
        return QUrl();
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
        return QString("QPushButton{border-image:url(:/resource/boss_l1.png);}");
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
        return QString(":/resource/boss_l1_mod");
    else
        return QString(":/resource/boss_l1_mod");
}
