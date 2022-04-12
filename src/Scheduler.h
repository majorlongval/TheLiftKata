#pragma once

#include <cstdint>
#include <vector>

#include "Request.h"
#include "Call.h"
namespace LiftKata
{

class Scheduler
{
    public:
        virtual ~Scheduler() = default;
        Scheduler();
        int nextFloor(const int currentFloor, const bool direction);
        void passCommand(Command* c);

    private:
        std::vector<Command*> commandQueue;
        void reschedule();
        bool isWaitingForRequest;
};

}