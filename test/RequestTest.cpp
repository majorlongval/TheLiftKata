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

<<<<<<< HEAD
TEST_F(RequestTest, floorValue_ShouldReturnTheRequestFloorValue)
{
    Request r(7);
    EXPECT_EQ(7, r.floorValue());
}

=======
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
>>>>>>> 6f1046b61fb539d99c6c3c6f6d9f5c4769022fb6
}