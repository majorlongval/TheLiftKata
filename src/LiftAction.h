#pragma once

#include <cstdint>


namespace LiftKata
{
    enum Direction {up, down, noDirection};
    struct LiftAction
{
    uint8_t   callingFloor;
    Direction callingDirection;
    bool      doorCallingState;
};
}
