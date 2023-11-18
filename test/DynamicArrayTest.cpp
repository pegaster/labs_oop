#include <gtest/gtest.h>
#include "Allocator.h"
#include "DynamicArray.h"
#include <map>


TEST(DynamicArrayDefaultConstructor, BasicAssertions) {
    // arrange 
    int expectedSize = 0;
    // act
    DynamicArray<int, Allocator<int> > vect;
    
    // assert
   EXPECT_EQ(vect.getSize(), 0);
}


TEST(PushBack, BasicAssertions) {
    // arrange 
    DynamicArray<int, Allocator<int> > vect;
    int expectedSize = 1;
    // act
    vect.push_back(2);
    
    // assert
    EXPECT_EQ(vect.getSize(), 1);
    EXPECT_EQ(vect[0], 2);
}

TEST(PushBackOutOfBoundsExeption, BasicAssertions) {
    // arrange 
    DynamicArray<int, Allocator<int> > vect;
    int expectedSize = 1;
    // act
    vect.push_back(2);
    
    // assert
   EXPECT_THROW(vect[12];, std::out_of_range);
}


TEST(Iterators, BasicAssertions) {
    // arrange 
    int expectedSize = 0;
    DynamicArray<int, Allocator<int> > vect;
    for (int i = 0; i < 10; ++i){
        vect.push_back(i);
    }
    int res = 1;
    int i = 0;
    // act
    for (auto e : vect){
        if (e != i){
            res = 0;
            break;
        }
        i++;
    }
    
    // assert
    EXPECT_EQ(res, 1);
}