#pragma once
#include "Point.h"
#include "Figure.h"

class Triangle : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Triangle &object);
    friend std::istream& operator>>(std::istream& is, Triangle &object);
    protected:
        std::ostream &print(std::ostream& os) const override;
        std::istream &read(std::istream& is) override;
    public:
        Triangle();
        Triangle(const Point* points);
        Point getRotationCenter() const override;
        bool operator==(const Figure &other) const override;
        Figure& operator=(const Figure &other) override;
        Figure& operator=(Figure &&other) override;
        bool operator==(const Triangle &other) const;
        Triangle& operator=(const Triangle &other);
        Triangle& operator=(Triangle &&other);
        operator double() const override;
};

std::ostream& operator<<(std::ostream& os, const Triangle &object);
std::istream& operator>>(std::istream& is, Triangle &object);