#include <gtest/gtest.h>
#include "Octagon.h"

TEST(OctagonPointConstructor, HappyPath) {
    // arrange 
    Point octagonPoints[8];
    octagonPoints[0] = Point{0,0};
    octagonPoints[1] = Point{2,0};
    octagonPoints[2] = Point{3,1};
    octagonPoints[3] = Point{3,3};
    octagonPoints[4] = Point{2,4};
    octagonPoints[5] = Point{0,4};
    octagonPoints[6] = Point{-1,3};
    octagonPoints[7] = Point{-1,1};
 
    // act
    Octagon octagon{octagonPoints};
    EXPECT_EQ(octagon.getPoints()[0], octagonPoints[0]);
    EXPECT_EQ(octagon.getPoints()[1], octagonPoints[1]);
    EXPECT_EQ(octagon.getPoints()[2], octagonPoints[2]);
    EXPECT_EQ(octagon.getPoints()[3], octagonPoints[3]);
    EXPECT_EQ(octagon.getPoints()[4], octagonPoints[4]);
    EXPECT_EQ(octagon.getPoints()[5], octagonPoints[5]);
    EXPECT_EQ(octagon.getPoints()[6], octagonPoints[6]);
    EXPECT_EQ(octagon.getPoints()[7], octagonPoints[7]);
}

TEST(OctagonPointConstructor, SomePointsOnOneLine) {
    // arrange 
    Point octagonPoints[8];
    octagonPoints[0] = Point{2,4};
    octagonPoints[1] = Point{4,8};
    octagonPoints[2] = Point{3,6};
    octagonPoints[3] = Point{3,3};
    octagonPoints[4] = Point{2,4};
    octagonPoints[5] = Point{0,4};
    octagonPoints[6] = Point{-1,3};
    octagonPoints[7] = Point{-1,1};
    // assert
    EXPECT_THROW(Octagon octagon{octagonPoints};, std::invalid_argument);

}

TEST(OctagonPointConstructor, ZeroLenSide) {
    // arrange 
    Point octagonPoints[8];
    octagonPoints[0] = Point{0,0};
    octagonPoints[1] = Point{0,0};
    octagonPoints[2] = Point{3,1};
    octagonPoints[3] = Point{3,3};
    octagonPoints[4] = Point{2,4};
    octagonPoints[5] = Point{0,4};
    octagonPoints[6] = Point{-1,3};
    octagonPoints[7] = Point{-1,1};

    // assert
    EXPECT_THROW(Octagon Octagon{octagonPoints};, std::invalid_argument);
}

TEST(OctagonGetRotationCenter, HappyPath) {
    // arrange 
    Point octagonPoints[8];
    octagonPoints[0] = Point{0,0};
    octagonPoints[1] = Point{2,0};
    octagonPoints[2] = Point{3,1};
    octagonPoints[3] = Point{3,3};
    octagonPoints[4] = Point{2,4};
    octagonPoints[5] = Point{0,4};
    octagonPoints[6] = Point{-1,3};
    octagonPoints[7] = Point{-1,1};
    Octagon Octagon{octagonPoints};
    Point expectedCenter = Point{1, 2};
    // act
    Point center = Octagon.getRotationCenter();

    // assert
   EXPECT_DOUBLE_EQ(center.getX(), expectedCenter.getX());
   EXPECT_DOUBLE_EQ(center.getY(), expectedCenter.getY());
}

TEST(OctagonSquareCalculation, HappyPath) {
    // arrange 
    Point octagonPoints[8];
    octagonPoints[0] = Point{0,0};
    octagonPoints[1] = Point{2,0};
    octagonPoints[2] = Point{3,1};
    octagonPoints[3] = Point{3,3};
    octagonPoints[4] = Point{2,4};
    octagonPoints[5] = Point{0,4};
    octagonPoints[6] = Point{-1,3};
    octagonPoints[7] = Point{-1,1};
    Octagon Octagon{octagonPoints};
    double expectedSquare = 14;
    // act
    
    double square = (double) Octagon;

    // assert
    EXPECT_DOUBLE_EQ(square, expectedSquare);
}