#include <cstdint>
#include <iostream>
#include <ostream>

#include "Lift.h"

using namespace LiftKata;

Lift::Lift():
doorState(false), 
currentFloor(0),
currentDirection(noDirection)
{}

bool Lift::isOpen() 
{
    return this->doorState;    
}

void Lift::open()
{
    this->doorState = true;
}

void Lift::close() 
{
    this->doorState = false;
}

uint8_t Lift::floor()
{
    return this->currentFloor;
}

Direction Lift::direction()
{
    return currentDirection;
}

void LiftKata::Lift::call(uint8_t sourceFloor, Direction direction) 
{
    if (this->currentFloor - sourceFloor < 0)
    {
        this->currentDirection = up;
    }
    else if (this->currentFloor - sourceFloor > 0) 
    {
        this->currentDirection = down;
    }
    else
    {
        this->currentDirection = noDirection;
    }
    this->currentFloor = sourceFloor; 
}
