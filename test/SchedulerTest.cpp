#include <iostream>
#include <ostream>
#include "gtest.h"
#include <vector>

#include "Command.h"
#include "Scheduler.h"
#include "Request.h"


using namespace std;

using namespace LiftKata;

namespace 
{
class SchedulerTest : public ::testing::Test
{
    protected:
        SchedulerTest(){}
        virtual ~SchedulerTest(){}
        Scheduler scheduler = Scheduler();
        const bool GOING_UP = true;
        const bool GOING_DOWN = false;
        const bool ANY_DIRECTION = true;
};

TEST_F(SchedulerTest, next_withEmptyScheduler_ShouldReturnCurrentPosition)
{
    int nextFloor = scheduler.nextFloor(1, ANY_DIRECTION);
    EXPECT_EQ(1, nextFloor);
}

TEST_F(SchedulerTest, next_WithASingleCommand_ShouldReturnItsFloor)
{
    Request r(7);
    scheduler.passCommand(&r);
    int nextFloor = scheduler.nextFloor(0, GOING_UP);
    ASSERT_EQ(7, nextFloor);
}

TEST_F(SchedulerTest, next_WithTwoCommands_ShouldReturnTheNearestOnDirectionFloor)
{
    Request r(7);
    Call c(3, GOING_UP);
    scheduler.passCommand(&r);
    scheduler.passCommand(&c);
    int nextFloor = scheduler.nextFloor(0, GOING_UP);
    ASSERT_EQ(3, nextFloor);
}

}