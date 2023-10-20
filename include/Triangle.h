#pragma once
#include "Figure.h"

class Triangle : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Triangle& figure);
    friend std::istream& operator>>(std::istream& is, Triangle& figure);
    public:
        Triangle();
        Triangle(const Point* points);
        virtual ~Triangle() = default;
        
        virtual std::ostream& print(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;

        virtual operator double() const override;
        virtual Point getRotationCenter() const override;
        
        Triangle& operator=(const Triangle& other);
        Triangle& operator=(Triangle&& other);
        bool operator==(const Triangle& other) const;
        virtual Figure& operator=(Figure&& other) override;
        virtual Figure& operator=(const Figure& other) override;
        virtual bool operator==(const Figure& other) const override;
};

std::ostream& operator<<(std::ostream& os, const Triangle& figure);
std::istream& operator>>(std::istream& is, Triangle& figure);