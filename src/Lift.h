#pragma once

#include <cstdint>
#include <vector>
#include "LiftCall.h"
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
    void appendToCallQueue(int floor, bool direction);
    void callFromQueue();
    bool direction();

private:
    int currentFloor;
    bool isWaitingForRequest;
    std::vector<LiftCall> callQueue;
    bool currentDirection;
};
}