#pragma once
#include "Point.h"
#include "Figure.h"

class Hexagon : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Hexagon &object);
    friend std::istream& operator>>(std::istream& is, Hexagon &object);
    protected:
        std::ostream &print(std::ostream& os) const override;
        std::istream &read(std::istream& is) override;
    public:
        Hexagon();
        static Figure *create(const Point* points);
        Hexagon(const Point* points);
        Point getRotationCenter() const override;
        bool operator==(const Figure &other) const override;
        Figure& operator=(const Figure &other) override;
        Figure& operator=(Figure &&other) override;
        bool operator==(const Hexagon &other) const;
        Hexagon& operator=(const Hexagon &other);
        Hexagon& operator=(Hexagon &&other);
        operator double() const override;
};

std::ostream& operator<<(std::ostream& os, const Hexagon &object);
std::istream& operator>>(std::istream& is, Hexagon &object);