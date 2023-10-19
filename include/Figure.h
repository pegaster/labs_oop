#pragma once
#include "Point.h"
#include <iostream>

class Figure {
    friend std::ostream& operator<<(std::ostream& os, const Figure &object);
    friend std::istream& operator>>(std::istream& is, Figure &object);
    protected:
        Point *points_;
        virtual std::ostream &print(std::ostream& os) const = 0;
        virtual std::istream &read(std::istream& is) = 0;
        Figure();

    public:
        virtual Point getRotationCenter() const;
        virtual bool operator==(const Figure &other) const = 0;
        virtual Figure& operator=(const Figure &other) = 0;
        virtual Figure& operator=(Figure &&other) = 0;
        const Point *getPoints() const;
        virtual operator double() const = 0;
        ~Figure();
};

std::ostream& operator<<(std::ostream& os, const Figure &object);
std::istream& operator>>(std::istream& is, Figure &object);
