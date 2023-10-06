#pragma once
#include <string>
#include <initializer_list>

void validateSymbol(unsigned char symbol, int radix);
int digitToNumber(unsigned char symbol, int radix);
unsigned char numberToDigit(int number, int radix);
unsigned char getLastNumber(int number, int radix);
unsigned char getSecondNumber(int number, int radix);
void validateString(const std::string &str, int radix);
void validateInitializerList(const std::initializer_list<unsigned char> &il, int radix);
void validateNonNegativeNumber(int number);
void validateNumberThatDigit(int number, int radix);
void validateRadix(int radix);
size_t getSignificantLength(unsigned char * data, size_t size);
