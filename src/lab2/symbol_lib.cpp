#include "symbol_lib.h"
#include <string>
#include <initializer_list>
#include <algorithm>
#include <iostream>

void validateSymbol(unsigned char symbol, int radix) {
    validateRadix(radix);
    if (!(symbol >= '0' && symbol < '0' + radix) && (symbol >= '0' && symbol <= '9')) {
        throw std::invalid_argument("Used digit from other number system");
    } else if (!(symbol >= '0' && symbol < '0' + radix)) {
        throw std::invalid_argument("Used not digit");
    }
}

int digitToNumber(unsigned char symbol, int radix) {
    validateSymbol(symbol, radix);
    return symbol - '0';
}

unsigned char numberToDigit(int number, int radix) {
    validateNumberThatDigit(number, radix);
    return number + '0';
}

unsigned char getLastNumber(int number, int radix) {
    validateNonNegativeNumber(number);
    return number % radix;
}

unsigned char getSecondNumber(int number, int radix) {
    validateNonNegativeNumber(number);
    return (number / radix) % radix;
}

void validateString(const std::string &str, int radix) {
    validateRadix(radix);
    for (unsigned char symbol : str) {
        validateSymbol(symbol, radix);
    }
}

void validateInitializerList(const std::initializer_list<unsigned char> &il, int radix) {
    validateRadix(radix);
    for (unsigned char symbol : il) {
        validateSymbol(symbol, radix);
    }
}

void validateNonNegativeNumber(int number) {
    if (number < 0) {
        throw std::invalid_argument("Number must be non-negative");
    }
}

void validateNumberThatDigit(int number, int radix) {
    validateRadix(radix);
    if (!(number >= 0 && number <= radix)) {
        throw std::invalid_argument("Number must be greater or equal 0 and less or equal radix");
    }
}

void validateRadix(int radix) {
    if (!(radix >= 2 && radix <= 10)) {
        throw std::invalid_argument("Radix must be greater or equal 0 and less or equal 10");
    }
}

size_t getSignificantLength(unsigned char * data, size_t size) {
    for (size_t i = size - 1; i >= 0 && i < size; --i) {
        if (data[i] != '0') {
            return i + 1;
        }
    }
    return size > 0 ? 1 : 0;
}
