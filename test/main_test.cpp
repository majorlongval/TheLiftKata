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

int main(int argc, char **argv) 
{ 
  ::testing::InitGoogleTest(&argc, argv); 
  return RUN_ALL_TESTS(); 
}