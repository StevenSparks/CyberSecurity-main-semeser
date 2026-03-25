#include "gtest/gtest.h"


class MemCorTest : public ::testing::Test {
 protected:
  virtual void SetUp() 
  {
    
  }
 
  virtual void TearDown() 
  {
    
  }

};

//main functions
TEST_F(MemCorTest, noFunctYet)
{

}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc,argv);
  return  RUN_ALL_TESTS();
}