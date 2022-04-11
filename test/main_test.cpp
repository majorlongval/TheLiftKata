#include <iostream>
#include <ostream>
#include "gtest.h"
#include <vector>

#include "Lift.h"

using namespace std;

using namespace LiftKata;

namespace 
{
class LiftKataTester : public ::testing::Test
{
    protected:
        LiftKataTester(){}
        virtual ~LiftKataTester(){}
        Lift lift = Lift();
        const bool GOING_UP = true;
        const bool GOING_DOWN = false;
        const bool ANY_DIRECTION = true;
};

TEST_F(LiftKataTester, callingLift_ShouldBringItAtMyFloor)
{
     lift.call(5, ANY_DIRECTION);
     vector<int> v1 {0, 5};
     EXPECT_EQ(v1, lift.visitedFloors());
}

TEST_F(LiftKataTester, requesting_fromACalledLift_ShouldMoveToFloor)
{
    lift.call(1, ANY_DIRECTION);
    lift.request(2);
    vector<int> v1 {0, 1, 2};
    EXPECT_EQ(v1, lift.visitedFloors());
}

TEST_F(LiftKataTester, calling_aCalledLift_ShouldWaitForARequest)
{
    lift.call(1, ANY_DIRECTION);

    lift.call(2, ANY_DIRECTION);
    vector<int> v1 {0, 1};
    EXPECT_EQ(v1, lift.visitedFloors());
}

TEST_F(LiftKataTester, calling_AfterARequest_ShouldAllowTheLiftToMoveAgain)
{
    lift.call(1, ANY_DIRECTION);
    lift.request(2);

    lift.call(3, ANY_DIRECTION);
    vector<int> v1 {0, 1, 2, 3};
    EXPECT_EQ(v1, lift.visitedFloors());
}

TEST_F(LiftKataTester, calling_aCalledLift_ShouldEventuallyGoToCall_AfterARequest)
{
    lift.call(1, ANY_DIRECTION);
    lift.call(3, ANY_DIRECTION);
    lift.request(2);
    vector<int> v1 {0, 1, 2, 3};
    EXPECT_EQ(v1, lift.visitedFloors());
}

TEST_F(LiftKataTester, ifNextCallingFloorIsHigher_LiftDirectionShouldBe_GoingUp)
{
    lift.call(1, ANY_DIRECTION);
    EXPECT_EQ(GOING_UP, lift.direction());
}

TEST_F(LiftKataTester, ifNextCallingFloorIsLower_LiftDirectionShouldBe_GoingDown)
{
    lift.call(1, ANY_DIRECTION);
    lift.request(2);
    lift.call(1, ANY_DIRECTION);
    EXPECT_EQ(GOING_DOWN, lift.direction());
}

TEST_F(LiftKataTester, lift_ShouldOnlyChangeDirection_WhenTheElevatorIsEmpty)
{
    lift.call(1, ANY_DIRECTION);
    lift.call(3, ANY_DIRECTION);
    lift.request(2);
    lift.call(1, ANY_DIRECTION);
    vector<int> v1 {0, 1, 2, 3};
    EXPECT_EQ(v1, lift.visitedFloors());
    lift.call(5, ANY_DIRECTION);
    EXPECT_EQ(v1, lift.visitedFloors());
    lift.request(4);
    vector<int> v2 {0, 1, 2, 3, 4, 5};
    EXPECT_EQ(v2, lift.visitedFloors());
    lift.request(2);
    vector<int> v3 {0, 1, 2, 3, 4, 5, 2, 1};
    EXPECT_EQ(v3, lift.visitedFloors());
}

TEST_F(LiftKataTester, lift_ShouldtakePassingByCalls)
{
    lift.call(1, ANY_DIRECTION);
    lift.call(2, ANY_DIRECTION);
    lift.request(5);
    lift.request(3);
    lift.call(4, ANY_DIRECTION);
    lift.request(1);
    vector<int> v1 = {0, 1, 2, 3, 4, 5, 1};
    EXPECT_EQ(v1, lift.visitedFloors());
}
}

int main(int argc, char **argv) 
{ 
  ::testing::InitGoogleTest(&argc, argv); 
  return RUN_ALL_TESTS(); 
}