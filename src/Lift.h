#pragma once

#include <cstdint>
#include <vector>
#include "LiftAction.h"
namespace LiftKata
{


class Lift
{
public:
    virtual ~Lift() = default;
    Lift();
    void call(int floor, bool direction);
    int floor() const;
    void request(int floor);

private:
    int currentFloor;
    bool isWaitingForRequest;

};
}