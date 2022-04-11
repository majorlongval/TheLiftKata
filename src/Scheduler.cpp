#include <cstdint>
#include <iostream>
#include <ostream>

#include "Scheduler.h"

using namespace LiftKata;
using namespace std;

Scheduler::Scheduler()
{}

int Scheduler::nextFloor(const int currentFloor, const bool direction)
{
    if (! commandQueue.empty())
    {
       Command* tmpCommand = commandQueue[0];
       return tmpCommand->floorValue();
    }
    return currentFloor;
}

void Scheduler::passCommand(Command* c)
{
    commandQueue.push_back(c);
}