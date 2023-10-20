#include <gtest/gtest.h>
#include "Hexagon.h"

TEST(HexagonPointConstructor, HappyPath) {
    // arrange 
    Point hexagonPoints[6];
    hexagonPoints[0] = Point{0,0};
    hexagonPoints[1] = Point{2,0};
    hexagonPoints[2] = Point{3,1};
    hexagonPoints[3] = Point{2,2};
    hexagonPoints[4] = Point{0,2};
    hexagonPoints[5] = Point{-1,1};
 
    // act
    Hexagon hexagon{hexagonPoints};
    EXPECT_EQ(hexagon.getPoints()[0], hexagonPoints[0]);
    EXPECT_EQ(hexagon.getPoints()[1], hexagonPoints[1]);
    EXPECT_EQ(hexagon.getPoints()[2], hexagonPoints[2]);
    EXPECT_EQ(hexagon.getPoints()[3], hexagonPoints[3]);
    EXPECT_EQ(hexagon.getPoints()[4], hexagonPoints[4]);
    EXPECT_EQ(hexagon.getPoints()[5], hexagonPoints[5]);
}

TEST(HexagonPointConstructor, SomePointsOnOneLine) {
    // arrange 
    Point hexagonPoints[6];
    hexagonPoints[0] = Point{2,4};
    hexagonPoints[1] = Point{4,8};
    hexagonPoints[2] = Point{3,6};
    hexagonPoints[3] = Point{3,3};
    hexagonPoints[4] = Point{2,4};
    hexagonPoints[5] = Point{0,4};
    // assert
    EXPECT_THROW(Hexagon hexagon{hexagonPoints};, std::invalid_argument);

}

TEST(HexagonPointConstructor, ZeroLenSide) {
    // arrange 
    Point hexagonPoints[6];
    hexagonPoints[0] = Point{0,0};
    hexagonPoints[1] = Point{0,0};
    hexagonPoints[2] = Point{3,1};
    hexagonPoints[3] = Point{3,3};
    hexagonPoints[4] = Point{2,4};
    hexagonPoints[5] = Point{0,4};

    // assert
    EXPECT_THROW(Hexagon hexagon{hexagonPoints};, std::invalid_argument);
}

TEST(HexagonGetRotationCenter, HappyPath) {
    // arrange 
    Point hexagonPoints[6];
    hexagonPoints[0] = Point{0,0};
    hexagonPoints[1] = Point{2,0};
    hexagonPoints[2] = Point{3,1};
    hexagonPoints[3] = Point{2,2};
    hexagonPoints[4] = Point{0,2};
    hexagonPoints[5] = Point{-1,1};
    Hexagon hexagon{hexagonPoints};
    Point expectedCenter = Point{1, 1};
    // act
    Point center = hexagon.getRotationCenter();

    // assert
   EXPECT_DOUBLE_EQ(center.getX(), expectedCenter.getX());
   EXPECT_DOUBLE_EQ(center.getY(), expectedCenter.getY());
}

TEST(HexagonSquareCalculation, HappyPath) {
    // arrange 
    Point hexagonPoints[6];
    hexagonPoints[0] = Point{0,0};
    hexagonPoints[1] = Point{2,0};
    hexagonPoints[2] = Point{3,1};
    hexagonPoints[3] = Point{2,2};
    hexagonPoints[4] = Point{0,2};
    hexagonPoints[5] = Point{-1,1};
    Hexagon hexagon{hexagonPoints};
    double expectedSquare = 6;
    // act
    
    double square = (double) hexagon;

    // assert
    EXPECT_DOUBLE_EQ(square, expectedSquare);
}