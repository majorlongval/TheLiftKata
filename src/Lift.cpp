#include <cstdint>
#include <iostream>
#include <ostream>

#include "Lift.h"

using namespace LiftKata;
using namespace std;

Lift::Lift():
    currentFloor(0),
    isWaitingForRequest(false),
    currentDirection(true),
    visitedFloorList({0})
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
        visitedFloorList.push_back(floor);
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
    visitedFloorList.push_back(floor);
    if (! callQueue.empty())
    {
        callFromCallQueue();
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

void Lift::callFromCallQueue()
{
    call(callQueue[0].callingFloor, callQueue[0].direction);
    callQueue.erase(callQueue.begin());
}

bool Lift::direction() const
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

vector<int> Lift::visitedFloors() const
{
    return visitedFloorList;
}