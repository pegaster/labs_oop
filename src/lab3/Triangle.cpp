#include "Triangle.h"
#include "Figure.h"
#include "ValidationCompositor.h"
#include <math.h>

std::ostream &Triangle::print(std::ostream& os) const {
    for (int i = 0; i < 3; i++) {
        os << points_[i];
        if (i < 2) {
            os << " ";
        }
    }
    return os;
}

std::istream &Triangle::read(std::istream& is) {
    for (int i = 0; i < 3; i++) {
        is >> points_[i];
    }
    return is;
}

Triangle::Triangle() {
    points_ = new Point[3];
}

Triangle::Triangle(const Point* points) {
    points = new Point[3];

    for (int i = 0; i < 3; i++) {
        points_[i] = points[i];
    }

    ValidationCompositor().validate(dynamic_cast<const Figure &>(*this));
}

bool Triangle::operator==(const Figure &other) const {
    try {
        const Triangle& other_triangle = dynamic_cast<const Triangle&>(other);
        return *this == other_triangle;
    } catch (const std::bad_cast &e) {
        return false;
    }
}

Figure& Triangle::operator=(const Figure &other) {
    try {
        const Triangle& other_triangle = dynamic_cast<const Triangle&>(other);
        return *this = other_triangle;
    } catch (const std::bad_cast &e) {
        throw std::invalid_argument("excepted is triangle");
    }
}

Figure& Triangle::operator=(Figure &&other) {
    try {
        const Triangle&& other_triangle = dynamic_cast<Triangle&&>(other);
        return *this = other_triangle;
    } catch (const std::bad_cast &e) {
        throw std::invalid_argument("excepted is triangle");
    }
}

bool Triangle::operator==(const Triangle &other) const {
    for (int i = 0; i < 3; i++) {
        bool flag = true;
        for (int j = 0; j < 3; j++) {
            if (!((points_[(i + j) % 3] - points_[i]) == (other.points_[j] - other.points_[0]))) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    
    return false;
}

Triangle& Triangle::operator=(const Triangle &other) {
    for (int i = 0; i < 3; i++) {
        points_[i] = other.points_[i];
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle &&other) {
    for (int i = 0; i < 3; i++) {
        points_[i] = other.points_[i];
    }

    other.points_ = nullptr;
    return *this;
}

Triangle::operator double() const {
    double s = 0;
    for (int i = 0; i < 3; i++) {
        s += points_[i].getX() * points_[(i + 1) % 3].getY() - points_[i].getY() * points_[(i + 1) % 3].getX();
    }
    return fabs(s / 2);
}

std::ostream& operator<<(std::ostream& os, const Triangle &object) {
    return object.print(os);
}

std::istream& operator>>(std::istream& is, Triangle &object) {
    return object.read(is);
}

Point Triangle::getRotationCenter() const {
    double x = 0, y = 0;
    for (int i = 0; i < 3; i++) {
        x += points_[i].getX();
        y += points_[i].getY();
    }

    return Point(x / 3, y / 3);
}
