#include <gtest/gtest.h>
#include "SixBuilder.h"
#include <string>

TEST(SixBuilderTest, HappyPath) {
  // arrange 
  std::string valueForBuilder = "2345678";
  size_t size = 3;

  // act
  Six objectInSomeState{SixBuilder().data(valueForBuilder).size(size).build()};


  // assert
  EXPECT_EQ(objectInSomeState.getSize(), 3);
  EXPECT_STREQ(objectInSomeState.getData().c_str(), "234");
}

