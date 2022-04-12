#pragma once

#include <cstdint>
#include <vector>

#include "Command.h"
namespace LiftKata
{

class Request: public Command
{
    public:
        Request(int floor);
         ~Request() = default;
        virtual bool isSameFloor(const Command& c) ;
        //virtual bool isSameDirection(const Command& c);
        virtual int floorValue() const;
        //virtual bool directionValue() const;
        virtual bool isNearerAndOnPath(const Command& c, const Lift& lift) const;

};
}