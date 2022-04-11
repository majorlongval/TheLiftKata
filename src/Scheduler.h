#pragma once

#include <cstdint>
#include <vector>
namespace LiftKata
{

class Scheduler
{
    public:
        virtual ~Scheduler() = default;
        Scheduler();
        int nextFloor(const int currentFloor, const bool direction);
};


}