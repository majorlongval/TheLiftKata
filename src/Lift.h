#pragma once

#include <cstdint>
namespace LiftKata
{

enum Direction {up, down, noDirection};
class Lift
{
    public:
        Lift();
        bool isOpen();        
        void open();
        void close();
        uint8_t floor();
        Direction direction();
        void call(uint8_t sourceFloor, Direction Direction);
    
    private:
        bool doorState;
        uint8_t currentFloor;
        Direction currentDirection;
        

};
}