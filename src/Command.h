#pragma once

#include <cstdint>
#include <vector>
namespace LiftKata
{
    const bool GOING_UP = true;
    const bool GOING_DOWN = false;
    const bool ANY_DIRECTION = true;
class Command
{
    public:
        virtual bool isSameFloor(const Command& c) = 0;
        virtual bool isSameDirection(const Command& c) = 0;
        virtual int floorValue() = 0;
    protected:
        int floor;
        bool direction;

};
}
