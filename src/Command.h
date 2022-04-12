#pragma once

#include "Request.h"
#include <cstdint>
#include <vector>

#include "Lift.h"

namespace LiftKata
{
    const bool GOING_UP = true;
    const bool GOING_DOWN = false;
    const bool ANY_DIRECTION = true;
class Command
{    
    public:
        virtual bool isSameFloor(const Command& c) = 0;
        virtual int floorValue() const = 0;
        virtual bool isNearerAndOnPath(const Command& c, const Lift& lift) const = 0;
    protected:
        int floor;
        bool direction;

};
}
