
#include "Request.h"
#include <cmath>

using namespace LiftKata;
using namespace std;

Request::Request(int floor)
{
    this->floor = floor;
}

bool Request::isSameDirection(const Command &c)
{
    return true;
}

bool Request::isSameFloor(const Command &c)
{
    if(this->floor == c.floor)
    {
        return true;
    }
    return false;
}

int Request::floorValue() const
{
    return this->floor;
}