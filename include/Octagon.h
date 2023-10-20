#pragma once
#include "Figure.h"

class Octagon : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Octagon& figure);
    friend std::istream& operator>>(std::istream& is, Octagon& figure);
    public:
        Octagon();
        Octagon(const Point* points);

        virtual ~Octagon() = default;
        static Figure* create(const Point* points);
        
        virtual std::ostream& print(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;

        virtual operator double() const override;
        virtual Point getRotationCenter() const override;
        
        Octagon& operator=(const Octagon& other);
        Octagon& operator=(Octagon&& other);
        bool operator==(const Octagon& other) const;

        virtual Figure& operator=(Figure&& other) override;
        virtual Figure& operator=(const Figure& other) override;
        virtual bool operator==(const Figure& other) const override;
};

std::ostream& operator<<(std::ostream& os, const Octagon& figure);
std::istream& operator>>(std::istream& is, Octagon& figure);