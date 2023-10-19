#pragma once
#include <iostream>
const double epsilon = 1e-9;

class Point {
    friend std::ostream &operator<<(std::ostream& os, const Point & object);
    friend std::istream &operator>>(std::istream& is, Point& object);
    private:
        double x_;
        double y_;
        std::ostream &print(std::ostream& os) const;
        std::istream &read(std::istream& is);
    public:
        Point();
        Point(double x, double y);
        double getX() const;
        double getY() const;
        ~Point() = default;
        Point(const Point &other);
        Point(Point &&other) noexcept;
        Point operator+(const Point &other) const;
        Point operator-(const Point &other) const;
        Point& operator=(const Point &other);
        bool operator==(const Point &other) const;
        Point& operator=(Point &&other);
};


std::ostream &operator<<(std::ostream& os, const Point& object);
std::istream &operator>>(std::istream& is, Point& object);
double dot(const Point &p1, const Point &p2);
double abs(const Point &p1);
double cos(const Point &p1, const Point &p2);
double cross(const Point &p1, const Point &p2);
bool isParallel(const Point &p1, const Point &p2);
Point intersection(const Point &p1, const Point &p2, const Point &p3, const Point &p4);
bool isCrossing(const Point &p1, const Point &p2, const Point &p3, const Point &p4);