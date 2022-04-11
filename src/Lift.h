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
    void addToRequestQueue(int floor);
    void callFromCallQueue();
    void requestFromRequestQueue();
    bool direction() const;
    std::vector<int> visitedFloors() const;
    const bool GOING_UP = true;
    const bool GOING_DOWN = false;
private:
    int currentFloor;
    bool isWaitingForRequest;
    std::vector<LiftCall> callQueue;
    std::vector<int> requestQueue;
    bool currentDirection;
    std::vector<int> visitedFloorList;
    bool isOnPath(int floor);

};
}