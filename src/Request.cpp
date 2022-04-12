#include<cmath>

#include "Request.h"


using namespace LiftKata;
using namespace std;

Request::Request(int floor)
{
    this->floor = floor;
}

//bool Request::isSameDirection(const Command &c)
//{
//    return true;
//}

bool Request::isSameFloor(const Command &c)
{
    if (this->floor == c.floorValue())
    {
        return true;
    }
    return false;
}

int Request::floorValue() const
{
    return this->floor;
}

//bool Request::directionValue() const
//{
//    return true;
//}

bool Request::isNearerAndOnPath(const Command& c, const Lift& lift) const
{}