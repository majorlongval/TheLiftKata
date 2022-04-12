#include "gtest.h"


#include "Request.h"


using namespace std;

using namespace LiftKata;

namespace 
{
class RequestTest : public ::testing::Test
{
    protected:
        RequestTest(){}
        virtual ~RequestTest(){}
};

TEST_F(RequestTest, isSameFloor_ShouldOnlyReturnTrueIfFloorsAreSame)
{
    Request lhs(1);
    Request rhs1(2);
    Request rhs2(1);
    EXPECT_FALSE(lhs.isSameFloor(rhs1));
    EXPECT_TRUE(lhs.isSameFloor(rhs2));
}

TEST_F(RequestTest, floorValue_ShouldReturnTheRequestFloorValue)
{
    Request r(7);
    EXPECT_EQ(7, r.floorValue());
}

}