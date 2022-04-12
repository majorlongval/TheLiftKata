#pragma once

#include <cstdint>
#include <vector>
#include "Command.h"
namespace LiftKata
{

class Call: public Command
{
    public:
        Call(int floor, bool direction);
        virtual ~Call() = default;
        virtual bool isSameFloor(const Command& c) ;
        virtual int floorValue() const;
        bool isSameDirection(const Call& c);
        bool directionValue() const;
        virtual bool isNearerAndOnPath(const Command& c, const Lift& lift) const;

};
}
