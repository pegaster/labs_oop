#include "SixBuilder.h"
#include <iostream>
#include <string>

SixBuilder & SixBuilder::data(std::string value) {
    if (value.size() == 0) {
        throw std::invalid_argument("Length must be greater than null");
    }

    object.data = new unsigned char[value.size()];
    std::copy(value.begin(), value.end(), object.begin());
    return *this;
}

SixBuilder & SixBuilder::size(size_t value) {
    object.size = value;
    return *this;
}

Six SixBuilder::build() {
    return object;
}