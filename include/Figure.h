#pragma once
#include <string>
#include "Point.h"

class Figure{
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    protected:
        Figure();
        Figure(std::string figureName);
        virtual std::ostream& print(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;

    public:
        virtual ~Figure();    
        virtual operator double() const = 0;
        virtual Point getRotationCenter() const = 0;
        virtual bool operator==(const Figure& other) const = 0;
        virtual Figure& operator=(Figure&& other)=0;
        virtual Figure& operator=(const Figure& other)=0;
        virtual const Point* getPoints() const ;
    protected:
        Point* points_;
    
};
std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);