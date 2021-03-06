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
     EXPECT_EQ(5, lift.floor());
}

TEST_F(LiftKataTester, requesting_fromACalledLift_ShouldMoveToFloor)
{
    lift.call(1, ANY_DIRECTION);
    lift.request(2);
    EXPECT_EQ(2, lift.floor());
}

TEST_F(LiftKataTester, calling_aCalledLift_ShouldWaitForARequest)
{
    lift.call(1, ANY_DIRECTION);

    lift.call(2, ANY_DIRECTION);

    EXPECT_EQ(1, lift.floor());
}

TEST_F(LiftKataTester, calling_AfterARequest_ShouldAllowTheLiftToMoveAgain)
{
    lift.call(1, ANY_DIRECTION);
    lift.request(2);

    lift.call(3, ANY_DIRECTION);

    EXPECT_EQ(3, lift.floor());
}

TEST_F(LiftKataTester, calling_aCalledLift_ShouldEventuallyGoToCall_AfterARequest)
{
    lift.call(1, ANY_DIRECTION);
    lift.call(3, ANY_DIRECTION);
    lift.request(2);
    lift.call(4, ANY_DIRECTION);

    EXPECT_EQ(3, lift.floor());
}

TEST_F(LiftKataTester, ifCallingFloorIsHigher_LiftDirectionShouldBe_GoingUp)
{
    lift.call(1, ANY_DIRECTION);
    EXPECT_EQ(GOING_UP, lift.direction());
}

TEST_F(LiftKataTester, ifCallingFloorIsLower_LiftDirectionShouldBe_GoingDown)
{
    lift.call(1, ANY_DIRECTION);
    lift.request(2);
    lift.call(1, ANY_DIRECTION);
    EXPECT_EQ(GOING_DOWN, lift.direction());
}
}

int main(int argc, char **argv) 
{ 
  ::testing::InitGoogleTest(&argc, argv); 
  return RUN_ALL_TESTS(); 
}