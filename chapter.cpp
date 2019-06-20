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
