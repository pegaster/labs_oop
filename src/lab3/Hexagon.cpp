#include "Hexagon.h"
#include "ValidationCompositor.h"
#include <math.h>

Figure *Hexagon::create(const Point* points) {
    return dynamic_cast<Figure *>(new Hexagon(points));
}

std::ostream &Hexagon::print(std::ostream& os) const {
    for (int i = 0; i < 6; i++) {
        os << points_[i];
        if (i < 2) {
            os << " ";
        }
    }
    return os;
}

std::istream &Hexagon::read(std::istream& is) {
    for (int i = 0; i < 6; i++) {
        is >> points_[i];
    }
    return is;
}

Hexagon::Hexagon() {
    points_ = new Point[6];
}

Hexagon::Hexagon(const Point* points) {
    points = new Point[6];
    for (int i = 0; i < 6; i++) {
        points_[i] = points[i];
    }
    ValidationCompositor().validate(dynamic_cast<const Figure &>(*this));
}

bool Hexagon::operator==(const Figure &other) const {
    try {
        const Hexagon& other_Hexagon = dynamic_cast<const Hexagon&>(other);
        return *this == other_Hexagon;
    } catch (const std::bad_cast &e) {
        return false;
    }
}

Figure& Hexagon::operator=(const Figure &other) {
    try {
        const Hexagon& other_Hexagon = dynamic_cast<const Hexagon&>(other);
        return *this = other_Hexagon;
    } catch (const std::bad_cast &e) {
        throw std::invalid_argument("excepted is Hexagon");
    }
}

Figure& Hexagon::operator=(Figure &&other) {
    try {
        const Hexagon&& other_Hexagon = dynamic_cast<Hexagon&&>(other);
        return *this = other_Hexagon;
    } catch (const std::bad_cast &e) {
        throw std::invalid_argument("excepted is Hexagon");
    }
}

bool Hexagon::operator==(const Hexagon &other) const {
    for (int i = 0; i < 6; i++) {
        bool flag = true;
        for (int j = 0; j < 6; j++) {
            if (!((points_[(i + j) % 6] - points_[i]) == (other.points_[j] - other.points_[0]))) {
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

Hexagon& Hexagon::operator=(const Hexagon &other) {
    for (int i = 0; i < 6; i++) {
        points_[i] = other.points_[i];
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon &&other) {
    for (int i = 0; i < 6; i++) {
        points_[i] = other.points_[i];
    }

    other.points_ = nullptr;
    return *this;
}

Hexagon::operator double() const {
    double s = 0;
    for (int i = 0; i < 6; i++) {
        s += points_[i].getX() * points_[(i + 1) % 6].getY() - points_[i].getY() * points_[(i + 1) % 6].getX();
    }
    return fabs(s / 2);
}

std::ostream& operator<<(std::ostream& os, const Hexagon &object) {
    return object.print(os);
}

std::istream& operator>>(std::istream& is, Hexagon &object) {
    return object.read(is);
}

Point Hexagon::getRotationCenter() const {
    double x = 0, y = 0;
    for (int i = 0; i < 6; i++) {
        x += points_[i].getX();
        y += points_[i].getY();
    }

    return Point(x / 6, y / 6);
}
