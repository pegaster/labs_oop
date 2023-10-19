#pragma once
#include "Point.h"
#include "Figure.h"

class Octagon : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Octagon &object);
    friend std::istream& operator>>(std::istream& is, Octagon &object);
    protected:
        std::ostream &print(std::ostream& os) const override;
        std::istream &read(std::istream& is) override;
    public:
        Octagon();
        static Figure *create(const Point* points);
        Octagon(const Point* points);
        Point getRotationCenter() const override;
        bool operator==(const Figure &other) const override;
        Figure& operator=(const Figure &other) override;
        Figure& operator=(Figure &&other) override;
        bool operator==(const Octagon &other) const;
        Octagon& operator=(const Octagon &other);
        Octagon& operator=(Octagon &&other);
        operator double() const override;
};

std::ostream& operator<<(std::ostream& os, const Octagon &object);
std::istream& operator>>(std::istream& is, Octagon &object);