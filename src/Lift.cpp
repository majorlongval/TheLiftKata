#include <cstdint>
#include <iostream>
#include <ostream>

#include "Lift.h"

using namespace LiftKata;
using namespace std;

Lift::Lift():
    currentFloor(0),
    isWaitingForRequest(false),
    currentDirection(true)
    {}

void Lift::call(int floor, bool direction)
{

    if (! isWaitingForRequest)
    {
        if (floor-currentFloor > 0)
        {
            currentDirection = true;
        }
        else
        {
            currentDirection = false;
        }
        
        currentFloor = floor;
    }
    else 
    {
        addToCallQueue(floor, direction);
    }
    isWaitingForRequest = true;
}

int Lift::floor() const
{
    return currentFloor;
}

void Lift::request(int floor)
{
    isWaitingForRequest = false;
    currentFloor = floor;
    if (! callQueue.empty())
    {
        callFromQueue();
    }
}

void Lift::addToCallQueue(int floor, bool direction)
{
    if (isOnPath(floor))
    {
        callQueue.insert(callQueue.begin(), {floor, direction});
    }
    else
    {
        callQueue.push_back({floor, direction});
    }

}

void Lift::callFromQueue()
{
    call(callQueue[0].callingFloor, callQueue[0].direction);
    callQueue.erase(callQueue.begin());
}

bool Lift::direction()
{
    return currentDirection;
}

bool Lift::isOnPath(int floor)
{
    if ((currentDirection && (floor - currentFloor > 0)) || (!currentDirection && (floor - currentFloor < 0)))
    {
        return true;
    } 
    return false;
}