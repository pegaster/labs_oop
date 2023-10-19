#include "Point.h"
#include <math.h>

Point::Point() {
    x_ = 0;
    y_ = 0;
}

Point::Point(double x, double y) {
    x_ = x;
    y_ = y;
}

double Point::getX() const {
    return x_;
}

double Point::getY() const {
    return y_;
}

Point::Point(const Point &other) {
    x_ = other.x_;
    y_ = other.y_;
}

Point::Point(Point &&other) noexcept {
    x_ = other.x_;
    y_ = other.y_;

    other.x_ = 0;
    other.y_ = 0;
}

Point Point::operator+(const Point &other) const {
    return Point(x_ + other.x_, y_ + other.y_);
}

Point Point::operator-(const Point &other) const {
    return Point(x_ - other.x_, y_ - other.y_);
}

Point& Point::operator=(const Point &other) {
    x_ = other.x_;
    y_ = other.y_;
    return *this;
}

Point& Point::operator=(Point &&other) {
    x_ = other.x_;
    y_ = other.y_;

    other.x_ = 0;
    other.y_ = 0;
    return *this;
}

bool Point::operator==(const Point &other) const {
    return (fabs(x_ - other.x_) <= epsilon) && (fabs(y_ - other.y_) <= epsilon);
}

std::ostream& Point::print(std::ostream& os) const {
    os << x_ << ' ' << y_;
    return os;
}

std::istream& Point::read(std::istream& is) {
    is >> x_ >> y_;
    return is;
}

std::ostream &operator<<(std::ostream& os, const Point & object) {
    return object.print(os);
}

std::istream &operator>>(std::istream& is, Point& object) {
    return object.read(is);
}

double dot(const Point &p1, const Point &p2) {
    return p1.getX() * p2.getX() + p1.getY() * p2.getY();
}

double abs(const Point &p1) {
    return sqrt(p1.getX() * p1.getX() + p1.getY() * p1.getY());
}

double cos(const Point &p1, const Point &p2) {
    return dot(p1, p2) / (abs(p1) * abs(p2));
}

double cross(const Point &p1, const Point &p2) {
    return p1.getX() * p2.getX() - p1.getY() * p2.getY();
}

bool isParallel(const Point &p1, const Point &p2) {
    return fabs(fabs(cos(p1, p2)) - 1) <= epsilon;
}

Point intersection(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    double k = (p4.getY() - p3.getY()) * (p2.getX() - p1.getX()) / ((p4.getX() - p3.getX()) * (p2.getY() - p1.getY()));
    double x = (p1.getX() - p3.getX() * k) / (1 - k);
    double y = (x - p1.getX()) * (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
    return Point(x, y);
}

bool isCrossing(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    if (isParallel(p2 - p1, p4 - p3)) {
        return false;
    }

    Point intersectionPoint = intersection(p1, p2, p3, p4);

    return (intersectionPoint.getX() < std::min(std::max(p1.getX(), p2.getX()), std::max(p3.getX(), p4.getX())) &&
        intersectionPoint.getX() > std::max(std::min(p1.getX(), p2.getX()), std::min(p3.getX(), p4.getX())) &&
        intersectionPoint.getY() > std::max(std::min(p1.getY(), p2.getY()), std::min(p3.getY(), p4.getY())) &&
        intersectionPoint.getY() > std::max(std::min(p1.getY(), p2.getY()), std::min(p3.getY(), p4.getY())));
}