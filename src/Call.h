#pragma once

#include <cstdint>
#include <vector>
#include "Command.h"
namespace LiftKata
{

class Call: public Command
{
    public:
        Call();
        virtual ~Call() = default;
        virtual bool isSameFloor(const Command& c) ;
        virtual bool isSameDirection(const Command& c);


};
}
