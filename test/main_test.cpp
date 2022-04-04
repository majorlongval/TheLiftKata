#include <iostream>
#include <ostream>
#include "gtest.h"

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
            virtual void SetUp(){}
            virtual void TearDown(){}
            Lift lift = Lift();
    };

};

TEST_F(LiftKataTester, doorShouldInitiallyBeClosed)
{
    ASSERT_FALSE(lift.isOpen());
}

TEST_F(LiftKataTester, doorCanBeOpened)
{
    lift.open();
    
    ASSERT_TRUE(lift.isOpen());
}

TEST_F(LiftKataTester, doorCanBeClosed)
{
    lift.open();
    
    lift.close();

    ASSERT_FALSE(lift.isOpen());
}

TEST_F(LiftKataTester, liftShouldInitiallyBeAtFloor0)
{
    ASSERT_EQ(lift.floor(), 0);
}

TEST_F(LiftKataTester, liftShouldInitiallyHaveNoDirection)
{
    ASSERT_EQ(lift.direction(), noDirection);
}

TEST_F(LiftKataTester, callFromUpperFloor_ShouldMakeLiftGoUp_IfAble)
{
    lift.call(1, up);
    EXPECT_EQ(lift.direction(), up);
    
}

TEST_F(LiftKataTester, callFromUpperFloor_ShouldChangeCurrentFloor_IfAble)
{
    lift.call(1, up);
    EXPECT_EQ(lift.floor(), 1);
}

TEST_F(LiftKataTester, callFromLowerFloor_ShouldMakeLiftGoDown_IfAble)
{
    lift.call(1, up);
    lift.call(0, up);
    EXPECT_EQ(lift.direction(), down);
}

int main(int argc, char **argv) 
{ 
  ::testing::InitGoogleTest(&argc, argv); 
  return RUN_ALL_TESTS(); 
}