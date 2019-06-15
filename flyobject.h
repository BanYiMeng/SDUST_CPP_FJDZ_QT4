#ifndef FLYOBJECT_H
#define FLYOBJECT_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>

class flyobjectData;

class flyobject
{
public:
    flyobject();
    flyobject(const flyobject &);
    flyobject &operator=(const flyobject &);
    ~flyobject();

private:
    QSharedDataPointer<flyobjectData> data;
};

#endif // FLYOBJECT_H