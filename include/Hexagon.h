#pragma once
#include "Figure.h"

class Hexagon : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Hexagon& figure);
    friend std::istream& operator>>(std::istream& is, Hexagon& figure);
    public:
        Hexagon();
        Hexagon(const Point* points);
        Hexagon(const Hexagon& other);
        Hexagon(Hexagon&& other);

        virtual ~Hexagon() = default;
        static Figure* create(const Point* points);
        
        virtual std::ostream& print(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;

        virtual operator double() const override;
        virtual Point getRotationCenter() const override;
        
        Hexagon& operator=(const Hexagon& other);
        Hexagon& operator=(Hexagon&& other);
        bool operator==(const Hexagon& other) const;

        virtual Figure& operator=(Figure&& other) override;
        virtual Figure& operator=(const Figure& other) override;
        virtual bool operator==(const Figure& other) const override;
};

std::ostream& operator<<(std::ostream& os, const Hexagon& figure);
std::istream& operator>>(std::istream& is, Hexagon& figure);