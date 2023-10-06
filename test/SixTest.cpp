#include <gtest/gtest.h>
#include "Six.h"
#include "SixBuilder.h"

// В итоге я сделал билдер, но не использую его здесь, потому что на мой вкус код с билдером получается менее читаемым в данном случае, не бейте меня дядя проверяющий

TEST(SixDefaultConstructorTest, HappyPath) {
  // act
  Six result{Six()}; // можно еще написать просто Six result; но я хотел чтобы код был единообразным

  // assert
  EXPECT_EQ(result.getSize(), 0);
  EXPECT_STREQ(result.getData().c_str(), "");
}

TEST(SixOneSymbolConstructorTest, HappyPath) {
  // arrange 
  unsigned char symbol = '4';
  size_t size = 8;

  // act
  Six result{Six(size, symbol)};

  // assert
  EXPECT_EQ(result.getSize(), size);
  EXPECT_STREQ(result.getData().c_str(), "44444444");
}

TEST(SixOneSymbolConstructorTest, LeadZeroes) {
  // arrange 
  unsigned char symbol = '0';
  size_t size = 8;

  // act
  Six result{Six(size, symbol)};

  // assert
  EXPECT_EQ(result.getSize(), 1);
  EXPECT_STREQ(result.getData().c_str(), "0");
}

TEST(SixOneSymbolConstructorTest, NotDigitSymbol) {
  // arrange 
  unsigned char symbol = 'a';
  size_t size = 8;

  // act & assert
  EXPECT_THROW({Six s(size, symbol);}, std::invalid_argument);
}

TEST(SixOneSymbolConstructorTest, NotSixNumberSystemDigitSymbol) {
  // arrange 
  unsigned char symbol = '6';
  size_t size = 8;

  // act & assert
  EXPECT_THROW({Six s(size, symbol);}, std::invalid_argument);
}

TEST(SixOneSymbolConstructorTest, ZeroLength) {
  // arrange 
  unsigned char symbol = '6';
  size_t size = 0;

  // act & assert
  EXPECT_THROW({Six s(size, symbol);}, std::invalid_argument);
}

TEST(SixStringConstructorTest, HappyPath) {
  // arrange 
  std::string str = "12345";
  std::string reversedStr;
  std::reverse_copy(str.begin(), str.end(), reversedStr.begin());

  // act
  Six result{Six(str)};

  // assert
  EXPECT_EQ(result.getSize(), str.size());
  EXPECT_STREQ(result.getData().c_str(), reversedStr.c_str());
}

TEST(SixStringConstructorTest, LeadZeroes) {
  // arrange 
  std::string str = "000125";

  // act
  Six result{Six(str)};

  // assert
  EXPECT_EQ(result.getSize(), 3);
  EXPECT_STREQ(result.getData().c_str(), "521");
}

TEST(SixStringConstructorTest, LeadZeroesZero) {
  // arrange 
  std::string str = "000000";

  // act
  Six result{Six(str)};

  // assert
  EXPECT_EQ(result.getSize(), 1);
  EXPECT_STREQ(result.getData().c_str(), "0");
}

TEST(SixStringConstructorTest, JustZero) {
  // arrange 
  std::string str = "0";

  // act
  Six result{Six(str)};

  // assert
  EXPECT_EQ(result.getSize(), 1);
  EXPECT_STREQ(result.getData().c_str(), "0");
}

TEST(SixStringConstructorTest, EmptyString) {
  // arrange 
  std::string str = "";

  // act & assert
  EXPECT_THROW({Six s(str);}, std::invalid_argument);
}

TEST(SixStringConstructorTest, NotSixNumberSystemDigitSymbol) {
  // arrange 
  std::string str = "126";

  // act & assert
  EXPECT_THROW({Six s(str);}, std::invalid_argument);
}

TEST(SixInitializerListConstructorTest, HappyPath) {
  // arrange 
  std::initializer_list<unsigned char> il{'1', '2', '3'};

  // act
  Six result{Six(il)};

  // assert
  EXPECT_EQ(result.getSize(), il.size());
  EXPECT_STREQ(result.getData().c_str(), "321");
}

TEST(SixInitializerListConstructorTest, LeadZeroes) {
  // arrange 
  std::initializer_list<unsigned char> il{'0', '0', '1', '2', '3'};

  // act
  Six result{Six(il)};

  // assert
  EXPECT_EQ(result.getSize(), 3);
  EXPECT_STREQ(result.getData().c_str(), "321");
}

TEST(SixInitializerListConstructorTest, LeadZeroesZero) {
  // arrange 
  std::initializer_list<unsigned char> il{'0', '0', '0', '0', '0'};

  // act
  Six result{Six(il)};

  // assert
  EXPECT_EQ(result.getSize(), 1);
  EXPECT_STREQ(result.getData().c_str(), "0");
}

TEST(SixInitializerListConstructorTest, JustZero) {
  // arrange 
  std::initializer_list <unsigned char> il{'0'};

  // act
  Six result{Six(il)};

  // assert
  EXPECT_EQ(result.getSize(), 1);
  EXPECT_STREQ(result.getData().c_str(), "0");
}

TEST(SixInitializerListConstructorTest, NotSixNumberSystemDigitSymbol) {
  // arrange 
  std::initializer_list <unsigned char> il{'1', '6'};

  // act & assert
  EXPECT_THROW({Six s(il);}, std::invalid_argument);
}

TEST(SixInitializerListConstructorTest, NotDigitSymbol) {
  // arrange 
  std::initializer_list <unsigned char> il{'1', 'a'};

  // act & assert
  EXPECT_THROW({Six s(il);}, std::invalid_argument);
}

TEST(SixCopyConstructorTest, HappyPath) {
  // arrange 
  Six old{Six("123")};

  // act
  Six result{Six(old)};

  // assert
  EXPECT_EQ(result.getSize(), old.getSize());
  EXPECT_STREQ(result.getData().c_str(), old.getData().c_str());
}

TEST(SixMoveConstructorTest, HappyPath) {
  // arrange 
  Six old{Six("123")};

  // act
  Six result{std::move(Six(old))};

  // assert
  EXPECT_EQ(result.getSize(), 3);
  EXPECT_STREQ(result.getData().c_str(), "321");
}

TEST(SixAddTest, EasyExample) {
  // arrange 
  Six a{Six("012345")};
  Six b{Six("543210")};

  // act
  Six result1{a + b};
  Six result2{b + a};

  // assert
  EXPECT_EQ(result1.getSize(), 6);
  EXPECT_STREQ(result1.getData().c_str(), "555555");
  EXPECT_EQ(result2.getSize(), result1.getSize());
  EXPECT_STREQ(result2.getData().c_str(), result1.getData().c_str());
}

TEST(SixAddTest, MediumExample) {
  // arrange 
  Six a{Six("11")};
  Six b{Six("500055")};

  // act
  Six result1{a + b};
  Six result2{b + a};

  // assert
  EXPECT_EQ(result1.getSize(), 6);
  EXPECT_STREQ(result1.getData().c_str(), "011005");
  EXPECT_EQ(result2.getSize(), result1.getSize());
  EXPECT_STREQ(result2.getData().c_str(), result1.getData().c_str());
}

TEST(SixAddTest, MediumExample2) {
  // arrange 
  Six a{Six("1")};
  Six b{Six("5")};

  // act
  Six result1{a + b};
  Six result2{b + a};

  // assert
  EXPECT_EQ(result1.getSize(), 2);
  EXPECT_STREQ(result1.getData().c_str(), "01");
  EXPECT_EQ(result2.getSize(), result1.getSize());
  EXPECT_STREQ(result2.getData().c_str(), result1.getData().c_str());
}

TEST(SixAddTest, HardExample) {
  // arrange 
  Six a{Six("1155443")};
  Six b{Six("500055")};

  // act
  Six result1{a + b};
  Six result2{b + a};

  // assert
  EXPECT_EQ(result1.getSize(), 7);
  EXPECT_STREQ(result1.getData().c_str(), "2455502");
  EXPECT_EQ(result2.getSize(), result1.getSize());
  EXPECT_STREQ(result2.getData().c_str(), result1.getData().c_str());
}

TEST(SixAddTest, EmptyPlusFull) {
  // arrange 
  Six a{Six()};
  Six b{Six("500055")};

  // act & assert
  EXPECT_THROW(a + b, std::logic_error);
  EXPECT_THROW(b + a, std::logic_error);
}

TEST(SixAddTest, EmptyPlusEmpty) {
  // arrange 
  Six a{Six()};
  Six b{Six()};

  // act & assert
  EXPECT_THROW(a + b, std::logic_error);
}

TEST(SixRemoveTest, EasyExample) {
  // arrange 
  Six a{Six("54321")};
  Six b{Six("1111")};

  // act
  Six result{a - b};

  // assert
  EXPECT_EQ(result.getSize(), 5);
  EXPECT_STREQ(result.getData().c_str(), "01235");
}

TEST(SixRemoveTest, MediumExample) {
  // arrange 
  Six a{Six("10000")};
  Six b{Six("11")};

  // act
  Six result{a - b};

  // assert
  EXPECT_EQ(result.getSize(), 4);
  EXPECT_STREQ(result.getData().c_str(), "5455");
}

TEST(SixRemoveTest, LessMinusGreater) {
  // arrange 
  Six a{Six("101")};
  Six b{Six("122")};

  // act & assert
  EXPECT_THROW(a - b, std::logic_error);
}

TEST(SixRemoveTest, EqualMinusEqual) {
  // arrange 
  Six a{Six("201")};
  Six b{Six("201")};

  // act
  Six result{a - b};

  // assert
  EXPECT_EQ(result.getSize(), 1);
  EXPECT_STREQ(result.getData().c_str(), "0");
}

TEST(SixRemoveTest, EmptyMinusFull) {
  // arrange 
  Six a{Six()};
  Six b{Six("122")};

  // act & assert
  EXPECT_THROW(a - b, std::logic_error);
  EXPECT_THROW(b - a, std::logic_error);
}

TEST(SixRemoveTest, EmptyMinusEmpty) {
  // arrange 
  Six a{Six()};
  Six b{Six()};

  // act & assert
  EXPECT_THROW(a - b, std::logic_error);
  EXPECT_THROW(b - a, std::logic_error);
}

TEST(SixCompareTest, LongestVSShortest) {
  // arrange 
  Six a{Six("10000")};
  Six b{Six("100")};

  // act
  bool result1 = a < b;
  bool result2 = b < a;
  bool result3 = a > b;
  bool result4 = b > a;
  bool result5 = a == b;
  bool result6 = b == a;

  EXPECT_FALSE(result1);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(result3);
  EXPECT_FALSE(result4);
  EXPECT_FALSE(result5);
  EXPECT_FALSE(result6);
}

TEST(SixCompareTest, SameLength) {
  // arrange 
  Six a{Six("10025")};
  Six b{Six("10000")};

  // act
  bool result1 = a < b;
  bool result2 = b < a;
  bool result3 = a > b;
  bool result4 = b > a;
  bool result5 = a == b;
  bool result6 = b == a;

  EXPECT_FALSE(result1);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(result3);
  EXPECT_FALSE(result4);
  EXPECT_FALSE(result5);
  EXPECT_FALSE(result6);
}

TEST(SixCompareTest, Equal) {
  // arrange 
  Six a{Six("10000")};
  Six b{Six("10000")};

  // act
  bool result1 = a < b;
  bool result2 = b < a;
  bool result3 = a > b;
  bool result4 = b > a;
  bool result5 = a == b;
  bool result6 = b == a;

  EXPECT_FALSE(result1);
  EXPECT_FALSE(result2);
  EXPECT_FALSE(result3);
  EXPECT_FALSE(result4);
  EXPECT_TRUE(result5);
  EXPECT_TRUE(result6);
}

TEST(SixCompareTest, EmptyVSFull) {
  // arrange 
  Six a{Six()};
  Six b{Six("1000")};

  // act & assert
  EXPECT_THROW(a < b, std::logic_error);
  EXPECT_THROW(b < a, std::logic_error);
  EXPECT_THROW(a > b, std::logic_error);
  EXPECT_THROW(b > a, std::logic_error);
  EXPECT_THROW(a == b, std::logic_error);
  EXPECT_THROW(b == a, std::logic_error);
}

TEST(SixCompareTest, EmptyVSEmpty) {
  // arrange 
  Six a{Six()};
  Six b{Six()};

  // act & assert
  EXPECT_THROW(a < b, std::logic_error);
  EXPECT_THROW(b < a, std::logic_error);
  EXPECT_THROW(a > b, std::logic_error);
  EXPECT_THROW(b > a, std::logic_error);
  EXPECT_THROW(a == b, std::logic_error);
  EXPECT_THROW(b == a, std::logic_error);
}

TEST(SixPrintTest, HappyPath) {
  // arrange 
  Six a{Six("1234")};

  // act
  testing::internal::CaptureStdout();
  std::cout << a;
  std::string output = testing::internal::GetCapturedStdout();

  // assert
  EXPECT_STREQ(output.c_str(), "1234");
}

TEST(SixPrintTest, LeadZeroes) {
  // arrange 
  Six a{Six("00001234")};

  // act
  testing::internal::CaptureStdout();
  std::cout << a;
  std::string output = testing::internal::GetCapturedStdout();

  // assert
  EXPECT_STREQ(output.c_str(), "1234");
}

TEST(SixPrintTest, Empty) {
  // arrange 
  Six a{Six()};

  // act & assert
  EXPECT_THROW(std::cout << a, std::logic_error);
}
