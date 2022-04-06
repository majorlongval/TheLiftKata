#include <cstdint>
#include <iostream>
#include <ostream>

#include "Lift.h"

using namespace LiftKata;

Lift::Lift():
    currentFloor(0),
    isWaitingForRequest(false)
    {}

void Lift::call(int floor, bool direction)
{
    if (! isWaitingForRequest)
    {
        currentFloor = floor;
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

    
}