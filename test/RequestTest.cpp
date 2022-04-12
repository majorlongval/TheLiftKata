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

TEST_F(RequestTest, isSameDirection_ShouldAlwaysReturnTrue)
{
    Request lhs(1);
    Request rhs(2);
    EXPECT_TRUE(lhs.isSameDirection(rhs));
}

TEST_F(RequestTest, floorValue_ShouldReturnFloorValueOfRequest)
{
    Request request(7)

    EXPECT_EQ(7, request.floorValue())
}

TEST_F(RequestTest, isSameFloor_ShouldOnlyReturnTrueIfSameFloor)
{
    Request lhs(1);
    Request rhs1(2);
    EXPECT_FALSE(lhs.isSameFloor(rhs1));
    Request rhs2(1);
    EXPECT_TRUE(lhs.isSameFloor(rhs2));
}
}