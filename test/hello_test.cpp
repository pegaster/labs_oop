#include <gtest/gtest.h>
#include <string>
#include "../include/lib.h"

TEST(calculateAmmountOfBreaksTest, Should9) {
  // arrange 
  int n {5};
  int m {6};

  // act
  int result;
  EXPECT_NO_THROW({
    result = calculateAmmountOfBreaks(n, m);
  });

  // assert
  EXPECT_EQ(result, 9);
}

TEST(calculateAmmountOfBreaksTest, ShouldThrowInvalidArgumnetExceptionN) {
  // arrange 
  int n {-5};
  int m {6};

  // act
  int result;
  EXPECT_THROW({
    result = calculateAmmountOfBreaks(n, m);
  }, std::invalid_argument);
}

TEST(calculateAmmountOfBreaksTest, ShouldThrowInvalidArgumnetExceptionM) {
  // arrange 
  int n {5};
  int m {-6};

  // act
  EXPECT_THROW({
    calculateAmmountOfBreaks(n, m);
  }, std::invalid_argument);
}

TEST(calculateAmmountOfBreaksTest, ShouldThrowInvalidArgumnetExceptionCheckMessageN) {
  // arrange 
  int n {-5};
  int m {6};

  // act
  try {
    calculateAmmountOfBreaks(n, m);
  } catch (std::exception& ex) {
    EXPECT_STREQ("n must be greater than 0", ex.what());
  }
}

TEST(calculateAmmountOfBreaksTest, ShouldThrowInvalidArgumnetExceptionCheckMessageM) {
  // arrange 
  int n {5};
  int m {-6};

  // act
  try {
    calculateAmmountOfBreaks(n, m);
  } catch (std::exception& ex) {
    EXPECT_STREQ("m must be greater than 0", ex.what());
  }
}