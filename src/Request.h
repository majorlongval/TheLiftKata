#pragma once

#include <cstdint>
#include <vector>
#include "Command.h"
namespace LiftKata
{

class Request: public Command
{
    public:
        Request(int floor);
        virtual ~Request() = default;
        virtual bool isSameFloor(const Command& c) ;
        virtual bool isSameDirection(const Command& c);


};
}