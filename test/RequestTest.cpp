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
}