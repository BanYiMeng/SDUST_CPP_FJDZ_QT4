#include "flyobject.h"

class flyobjectData : public QSharedData
{
public:

};

flyobject::flyobject() : data(new flyobjectData)
{

}

flyobject::flyobject(const flyobject &rhs) : data(rhs.data)
{

}

flyobject &flyobject::operator=(const flyobject &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

flyobject::~flyobject()
{

}
