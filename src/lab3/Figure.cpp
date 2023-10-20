#include "Figure.h"
#include <iostream>

const Point* Figure::getPoints() const {
    return points_;
};

Figure::~Figure() {
    if (points_ != nullptr) {
        delete[] points_;
    }
}

Figure::Figure() {
    points_ = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Figure &object) {
    return object.print(os);
}

std::istream& operator>>(std::istream& is, Figure &object) {
    return object.read(is);
}