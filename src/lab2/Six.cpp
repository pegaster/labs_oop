// Copyright 2023 SomeName

#include "Six.h"
#include "symbol_lib.h"
#include <initializer_list>
#include <algorithm>
#include <string>

Six::Six() {
    size = 0;
    data = nullptr;
}

Six::Six(const size_t & n, unsigned char t = '0') {
    if (n == 0) {
        throw std::invalid_argument("length must be greater than 0");
    }
    validateSymbol(t, 6);
    size = n;
    data = new unsigned char[size];
    for (unsigned char &symbol : *this) {
        symbol = t;
    }
    size = getSignificantLength(data, size);
}

Six::Six(const std::initializer_list<unsigned char> &t) {
    if (t.size() == 0) {
        throw std::invalid_argument("length must be greater than 0");
    }
    validateInitializerList(t, 6);
    size = t.size();
    data = new unsigned char[size];
    std::reverse_copy(t.begin(), t.end(), data);
    size = getSignificantLength(data, size);
}

Six::Six(const std::string &t) {
    if (t.size() == 0) {
        throw std::invalid_argument("length must be greater than 0");
    }
    validateString(t, 6);
    size = t.size();
    data = new unsigned char[size];
    std::reverse_copy(t.begin(), t.end(), data);
    size = getSignificantLength(data, size);
}

Six::Six(const Six& other) {
    size = other.size;
    data = new unsigned char[size];
    std::copy(other.begin(), other.end(), data);
    size = getSignificantLength(data, size);
}

Six::Six(Six&& other) noexcept {
    size = other.size;
    data = other.data;

    other.size = 0;
    other.data = nullptr;
}

Six::~Six() noexcept {
    if (data != nullptr) {
        delete[] data;
    }
}

unsigned char* Six::begin() const {
    return data;
}

unsigned char* Six::end() const {
    return data + size;
}



Six Six::remove(const Six& other) const {
    if (this->data == nullptr || other.data == nullptr) {
        throw std::logic_error("Empty object is not removeable");
    }
    if (lessThan(other)) {
        throw std::logic_error("Left number less than right");
    }

    Six result = Six(std::max(size, other.size), '0');

    int carry = 0;
    for (size_t i = 0; i < std::min(size, other.size); ++i) {
        int delta = digitToNumber(data[i], 6) - digitToNumber(other.data[i], 6) - carry;
        if (delta < 0) {
            carry = 1;
            delta += 6;
        } else {
            carry = 0;
        }
        result.data[i] = numberToDigit(getLastNumber(delta, 6), 6);
        //carry = getSecondNumber(delta, 6);
    }

    
    for (size_t i = std::min(size, other.size); i < size; ++i) {
        int delta = digitToNumber(data[i], 6) - carry;
        if (delta < 0) {
            carry = 1;
            delta += 6;
        } else {
            carry = 0;
        }
        result.data[i] = numberToDigit(getLastNumber(delta, 6), 6);
        //carry = getSecondNumber(delta, 6);
    }

    result.size = getSignificantLength(result.data, std::max(size, other.size));

    return result;

}

Six Six::add(const Six& other) const {
    if (data == nullptr || other.data == nullptr || size == 0 || other.size == 0) {
        throw std::logic_error("Empty object is not addable");
    }
    int carry = 0;
    size_t len;
    Six result{Six(std::max(size, other.size) + 1, '0')}; 
    const Six &longest = size > other.size ? *this : other;
    const Six &shortest = size <= other.size ? *this : other;
    
    for (size_t i = 0; i < shortest.size; ++i){

        result.data[i] = numberToDigit(getLastNumber((digitToNumber(shortest.data[i], 6) + digitToNumber(longest.data[i], 6) + carry), 6), 6);
        carry = getSecondNumber(digitToNumber(shortest.data[i], 6) + digitToNumber(longest.data[i], 6) + carry, 6);
    }

    for (size_t i = shortest.size; i < longest.size; ++i){
        result.data[i] = numberToDigit(getLastNumber((digitToNumber(longest.data[i], 6) + carry), 6), 6);
        carry = getSecondNumber(digitToNumber(longest.data[i], 6) + carry, 6);
    }
    result.data[longest.size] = numberToDigit(carry, 6);
    result.size = getSignificantLength(result.data, std::max(size, other.size) + 1);
    //std::cout << getSignificantLength(data, std::max(size, other.size) + 1) << std::endl;
    return result;
}

bool Six::equals(const Six& other) const {
    if (this->data == nullptr || other.data == nullptr) {
        throw std::logic_error("Empty object is not compareable");
    }
    if (size != other.size) {
        return false;
    }

    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }

    return true;
}

bool Six::lessThan(const Six& other) const {
    if (this->data == nullptr || other.data == nullptr) {
        throw std::logic_error("Empty object is not compareable");
    }
    if (size != other.size) {
        return size < other.size;
    }

    for (size_t i = size - 1; i >= 0 && i <= size - 1; --i) {
        if (data[i] < other.data[i]) {
            return true;
        }
        if (data[i] > other.data[i]) {
            return false;
        }
    }

    return false;
}

bool Six::greaterThan(const Six& other) const {
    if (this->data == nullptr || other.data == nullptr) {
        throw std::logic_error("Empty object is not compareable");
    }
    if (size != other.size) {
        return size > other.size;
    }

    for (size_t i = size - 1; i >= 0 && i <= size - 1; --i) {
        if (data[i] > other.data[i]) {
            return true;
        }

        if (data[i] < other.data[i]) {
            return false;
        }
    }

    return false;
}

std::string Six::getData() const { // я решил делать копирование, потому что во-первых так будет проще сравнивать т.к. оно в строке, а во вторых, мы можем считать дату в переменную, а после удалить наш объект
    if (data == nullptr) {
        return std::string("");
    }
    std::string dataCopy;
    std::copy(begin(), end(), dataCopy.begin());
    return dataCopy;
}

size_t Six::getSize() const {
    return size;
}

std::ostream & Six::print(std::ostream& os) const {
    if (data == nullptr) {
        throw std::logic_error("Empty object is not printable");
    }
    for (size_t i = size - 1; i >= 0 && i < size; --i) {
        os << data[i];
    }
        
    return os;
}

Six Six::operator +(const Six& other) const {
    return add(other);
};

Six Six::operator -(const Six& other) const {
    return remove(other);
}

bool Six::operator ==(const Six& other) const {
    return equals(other);
}

bool Six::operator >(const Six& other) const {
    return greaterThan(other);
}

bool Six::operator <(const Six& other) const {
    return lessThan(other);
}

Six & Six::operator =(const Six& other) {
    if (data != nullptr) {
        delete[] data;
    }
    size = other.size;
    data = new unsigned char[size];
    std::copy(other.begin(), other.end(), data);
    size = getSignificantLength(data, size);
    return *this;
}

Six & Six::operator =(Six&& other) {
    if (data != nullptr) {
        delete[] data;
    }
    size = other.size;
    data = other.data;
    other.size = 0;
    other.data = nullptr;
    return *this;
}

std::ostream &operator <<(std::ostream& os, const Six& object) {
    return object.print(os);
}

std::istream &operator >>(std::istream& is, Six& object) {
    std::string buffer;
    is >> buffer;
    object = Six(buffer);
    return is;
}
