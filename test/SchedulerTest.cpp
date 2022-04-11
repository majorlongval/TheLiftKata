#include <iostream>
#include <ostream>
#include "gtest.h"
#include <vector>


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
    //scheduler.schedule()
}

}