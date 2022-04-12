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
        int nextFloorValue = commandQueue[0]->floorValue();
        commandQueue.erase(commandQueue.begin());
        reschedule();
        return nextFloorValue;
    }
    return currentFloor;
}

void Scheduler::passCommand(Command* c)
{
    commandQueue.push_back(c);
}

void Scheduler::reschedule()
{
    if (!(commandQueue.size() < 2))
    {
        Command* nearestOnPath = commandQueue[0];
        for (Command* command:commandQueue)
        {
            //if command.isOnPathAndNearer(nearestOnPath, Lift)
        }
    }
}