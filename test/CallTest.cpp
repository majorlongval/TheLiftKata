#include "Command.h"
#include "gtest.h"


#include "Call.h"


using namespace std;

using namespace LiftKata;

namespace 
{
class CallTest : public ::testing::Test
{
    protected:
        CallTest(){}
        virtual ~CallTest(){}
};

TEST_F(CallTest, isSameDirection_ShouldOnlyReturnTrueIfDirectionsAreSame)
{
    Call lhs(1, GOING_UP);
    Call rhs1(2, GOING_UP);
    Call rhs2(2, GOING_DOWN);

    EXPECT_TRUE(lhs.isSameDirection(rhs1));
    EXPECT_FALSE(lhs.isSameDirection(rhs2));
}

TEST_F(CallTest, isSameFloor_ShouldOnlyReturnTrueIfFloorsAreSame)
{
    Call lhs(1, GOING_UP);
    Call rhs1(2, GOING_UP);
    Call rhs2(1, GOING_UP);
    EXPECT_FALSE(lhs.isSameFloor(rhs1));
    EXPECT_TRUE(lhs.isSameFloor(rhs2));
}

TEST_F(CallTest, floorValue_ShouldReturnTheCallFloorValue)
{
    Call c(7, GOING_UP);
    EXPECT_EQ(7, c.floorValue());
}

TEST_F(CallTest, directionValue_ShouldReturnTheCallDirectionValue)
{
    Call c(7, GOING_UP);
    EXPECT_EQ(GOING_UP, c.directionValue());
}
}