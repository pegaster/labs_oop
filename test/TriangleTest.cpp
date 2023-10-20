#include <gtest/gtest.h>
#include "Triangle.h"

TEST(TrianglePointConstructor, HappyPath) {
    // arrange 
    Point trianglePoints[3];
    trianglePoints[0] = Point{0,0};
    trianglePoints[1] = Point{7,0};
    trianglePoints[2] = Point{2,3};
 
    // act
    Triangle triangle{trianglePoints};
    EXPECT_EQ(triangle.getPoints()[0], trianglePoints[0]);
    EXPECT_EQ(triangle.getPoints()[1], trianglePoints[1]);
    EXPECT_EQ(triangle.getPoints()[2], trianglePoints[2]);
}

TEST(TrianglePointConstructor, AllPointsOnOneLine) {
    // arrange 
    Point trianglePoints[3];
    trianglePoints[0] = Point{2,4};
    trianglePoints[1] = Point{4,8};
    trianglePoints[2] = Point{3, 6};

    // assert
    EXPECT_THROW(Triangle triangle{trianglePoints};, std::invalid_argument);

}

TEST(TrianglePointConstructor, ZeroLenSide) {
    // arrange 
    Point trianglePoints[3];
    trianglePoints[0] = Point{2,2};
    trianglePoints[1] = Point{2,2};
    trianglePoints[2] = Point{2,3};

    // assert
    EXPECT_THROW(Triangle triangle{trianglePoints};, std::invalid_argument);
}

TEST(TriangleGetRotationCenter, HappyPath) {
    // arrange 
    Point trianglePoints[3];
    trianglePoints[0] = Point{0,0};
    trianglePoints[1] = Point{7,0};
    trianglePoints[2] = Point{2,3};
    Triangle triangle{trianglePoints};
    Point expectedCenter = Point{3, 1};
    // act
    Point center = triangle.getRotationCenter();

    // assert
   EXPECT_DOUBLE_EQ(center.getX(), expectedCenter.getX());
   EXPECT_DOUBLE_EQ(center.getY(), expectedCenter.getY());
}

TEST(TriangleSquareCalculation, HappyPath) {
    // arrange 
    Point trianglePoints[3];
    trianglePoints[0] = Point{0,0};
    trianglePoints[1] = Point{5,0};
    trianglePoints[2] = Point{0,5};
    Triangle triangle{trianglePoints};
    double expectedSquare = 12.5;
    // act
    
    double square = (double) triangle;

    // assert
    EXPECT_DOUBLE_EQ(square, expectedSquare);
}