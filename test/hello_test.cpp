#include <gtest/gtest.h>
#include <string>
#include "../include/lib.h"

TEST(calculaclateAmmountOfBreaksTest, Should9) {
  // arrange 
  int n {5};
  int m {6};

  // act
  int result;
  EXPECT_NO_THROW({
    result = calculaclateAmmountOfBreaks(n, m);
  });

  // assert
  EXPECT_EQ(result, 9);
}

TEST(calculaclateAmmountOfBreaksTest, ShouldThrowInvalidArgumnetExceptionN) {
  // arrange 
  int n {-5};
  int m {6};

  // act
  int result;
  EXPECT_THROW({
    result = calculaclateAmmountOfBreaks(n, m);
  }, std::invalid_argument);
}

TEST(calculaclateAmmountOfBreaksTest, ShouldThrowInvalidArgumnetExceptionM) {
  // arrange 
  int n {5};
  int m {-6};

  // act
  EXPECT_THROW({
    calculaclateAmmountOfBreaks(n, m);
  }, std::invalid_argument);
}

TEST(calculaclateAmmountOfBreaksTest, ShouldThrowInvalidArgumnetExceptionCheckMessageN) {
  // arrange 
  int n {-5};
  int m {6};

  // act
  try {
    calculaclateAmmountOfBreaks(n, m);
  } catch (std::exception& ex) {
    EXPECT_STREQ("n must be greater than 0", ex.what());
  }
}

TEST(calculaclateAmmountOfBreaksTest, ShouldThrowInvalidArgumnetExceptionCheckMessageM) {
  // arrange 
  int n {5};
  int m {-6};

  // act
  try {
    calculaclateAmmountOfBreaks(n, m);
  } catch (std::exception& ex) {
    EXPECT_STREQ("m must be greater than 0", ex.what());
  }
}