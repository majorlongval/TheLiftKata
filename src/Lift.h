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
    void addToCallQueue(int floor, bool direction);
    void callFromQueue();
    bool direction();
    const bool GOING_UP = true;
    const bool GOING_DOWN = false;
private:
    int currentFloor;
    bool isWaitingForRequest;
    std::vector<LiftCall> callQueue;
    bool currentDirection;
    bool isOnPath(int floor);
};
}