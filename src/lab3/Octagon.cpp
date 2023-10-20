#include "Octagon.h"
#include "Point.h"
#include "ValidationCompositor.h"
#include <math.h>

Octagon::Octagon() {
    points_ = new Point[8];
}

Octagon::Octagon(const Point* points) {
    points_ = new Point[8];
    for (int i = 0; i < 8; ++i) {
        points_[i] = points[i];
    }

    ValidationCompositor validator;
    validator.validate(dynamic_cast<Figure&>(*this));
}

Figure* Octagon::create(const Point* points) {
    return dynamic_cast<Figure*>(new Octagon(points));
}

Octagon& Octagon::operator=(const Octagon& other) {
    for (int i = 0; i < 8; i++) {
        points_[i] = other.points_[i];
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) {
    if (points_ != nullptr) {
        delete[] points_;
    }
    points_ = other.points_;
    delete[] other.points_;
    other.points_=nullptr;
    return *this;
}

bool Octagon::operator==(const Octagon& other) const {
    for (int i = 0; i < 8; i++) {
        bool flag = true;
        for (int j = 0; j < 8; j++) {
            if (!((points_[(i + j) % 8] - points_[i]) == (other.points_[j] - other.points_[0]))) {
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

Figure& Octagon::operator=(Figure&& other) {
    try{
        Octagon&& other_Octagon = dynamic_cast<Octagon&&>(other);
        return *this = other_Octagon;
    }
    catch(const std::bad_cast &e) {
        throw std::invalid_argument("exepted Trap");

    }
    
}
Figure& Octagon::operator=(const Figure& other) {
    try{
        const Octagon& other_Octagon = dynamic_cast<const Octagon&>(other);
        return *this = other_Octagon;
    }
    catch(const std::bad_cast &e) {
        throw std::invalid_argument("exepted Octagon");

    }
}

bool Octagon::operator==(const Figure& other) const {
    try{
        const Octagon& other_Octagon = dynamic_cast<const Octagon&>(other);
        return *this== other_Octagon;
    }
    catch(const std::bad_cast &e) {
        return false;
    }
}

Point Octagon::getRotationCenter() const {
    double x = 0, y = 0;
    for (int i = 0; i < 8; i++) {
        x += points_[i].getX();
        y += points_[i].getY();
    }

    return Point(x / 8, y / 8);
}

Octagon::operator double() const {
    double s = 0;
    for (int i = 0; i < 8; i++) {
        s += points_[i].getX() * points_[(i + 1) % 8].getY() - points_[i].getY() * points_[(i + 1) % 8].getX();
    }
    return fabs(s / 2);
}


std::ostream& Octagon::print(std::ostream& os) const {
    for (int i = 0; i < 8; ++i) {
        os << points_[i];
        if (i < 8 - 1) {
            os << std::endl;
        }
    }
    os << std::endl;
    return os;
    
}
std::istream& Octagon::read(std::istream& is) {
    for (int i = 0; i < 8; ++i) {
        is >> points_[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Octagon& figure) {
    return figure.print(std::cout);
}

std::istream& operator>>(std::istream& is, Octagon& figure) {
    return figure.read(std::cin);
}