#include "Triangle.h"
#include "Point.h"
#include "ValidationCompositor.h"
#include <math.h>

Triangle::Triangle() {
    points_ = new Point[3];
}

Triangle::Triangle(const Point* points) {
    points_ = new Point[3];
    for (int i = 0; i < 3; ++i) {
        points_[i] = points[i];
    }

    ValidationCompositor validator;
    validator.validate(dynamic_cast<Figure&>(*this));
}

Triangle& Triangle::operator=(const Triangle& other) {
    for (int i = 0; i < 3; i++) {
        points_[i] = other.points_[i];
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) {
    if (points_ != nullptr) {
        delete[] points_;
    }
    points_ = other.points_;
    delete[] other.points_;
    other.points_=nullptr;
    return *this;
}

bool Triangle::operator==(const Triangle& other) const {
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

Figure& Triangle::operator=(Figure&& other) {
    try{
        Triangle&& other_Triangle = dynamic_cast<Triangle&&>(other);
        return *this = other_Triangle;
    }
    catch(const std::bad_cast &e) {
        throw std::invalid_argument("exepted Trap");

    }
    
}
Figure& Triangle::operator=(const Figure& other) {
    try{
        const Triangle& other_Triangle = dynamic_cast<const Triangle&>(other);
        return *this = other_Triangle;
    }
    catch(const std::bad_cast &e) {
        throw std::invalid_argument("exepted Triangle");

    }
}

bool Triangle::operator==(const Figure& other) const {
    try{
        const Triangle& other_Triangle = dynamic_cast<const Triangle&>(other);
        return *this== other_Triangle;
    }
    catch(const std::bad_cast &e) {
        return false;
    }
}

Point Triangle::getRotationCenter() const {
    double x = 0, y = 0;
    for (int i = 0; i < 3; i++) {
        x += points_[i].getX();
        y += points_[i].getY();
    }

    return Point(x / 3, y / 3);
}

Triangle::operator double() const {
    double s = 0;
    for (int i = 0; i < 3; i++) {
        s += points_[i].getX() * points_[(i + 1) % 3].getY() - points_[i].getY() * points_[(i + 1) % 3].getX();
    }
    return fabs(s / 2);
}


std::ostream& Triangle::print(std::ostream& os) const {
    for (int i = 0; i < 3; ++i) {
        os << points_[i];
        if (i < 3 - 1) {
            os << std::endl;
        }
    }
    os << std::endl;
    return os;
    
}
std::istream& Triangle::read(std::istream& is) {
    for (int i = 0; i < 3; ++i) {
        is >> points_[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Triangle& figure) {
    return figure.print(std::cout);
}

std::istream& operator>>(std::istream& is, Triangle& figure) {
    return figure.read(std::cin);
}