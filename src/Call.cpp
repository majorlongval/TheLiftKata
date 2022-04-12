#include <cmath>
#include "Call.h"

using namespace LiftKata;
using namespace std;

Call::Call(int floor, bool direction)
{
    this->floor = floor;
    this->direction = direction;
}

bool Call::isSameDirection(const Call &c)
{
    if (this->direction == c.directionValue())
    {
        return true;
    }
    return false;
}

bool Call::isSameFloor(const Command &c)
{
    if (this->floor == c.floorValue())
    {
        return true;
    }
    return false;
}

int Call::floorValue() const
{
    return this->floor;
}

bool Call::directionValue() const
{
    return this->direction;
}

bool Call::isNearerAndOnPath(const Command& c, const Lift& lift) const
{
}