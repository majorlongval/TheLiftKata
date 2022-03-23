#include <iostream>
#include <ostream>

#include "Lift.h"

Lift::Lift()
{
    std::cout<<"Creating a Lift"<<std::endl;
}

Lift::Lift(int startingFloor)
{
    std::cout<<"Creating a Lift on floor "<< startingFloor << std::endl;
}