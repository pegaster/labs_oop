#pragma once
#include "Figure.h"
#include "NumberConcept.h"

template<Number T> class Hexagon : public Figure<T>{
    template <Number U> friend std::ostream& operator<<(std::ostream& os, const Hexagon<U>& figure);
    template<Number U> friend std::istream& operator>>(std::istream& is, Hexagon<U>& figure);
    public:
        Hexagon();
        Hexagon(const std::shared_ptr<Point<T>> points);
        Hexagon(const Hexagon<T>& other);
        Hexagon(Hexagon<T>&& other);

        virtual ~Hexagon() = default;

        // std::string getFigureName() const;
        // Point* getPoints() const;
        static Hexagon<T> create(const std::shared_ptr<Point<T>> points);
        
        virtual std::ostream& print(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;

        virtual operator double() const override;
        virtual Point<T> center() const override;
        
        Hexagon<T>& operator=(Hexagon<T>& other);
        Hexagon<T>& operator=(Hexagon<T>&& other);
        bool operator==(Hexagon<T>& other);

        virtual Figure<T>& operator=(const Figure<T>&& other) override;
        virtual Figure<T>& operator=(const Figure<T>& other) override;
        virtual bool operator==(const Figure<T>& other) override;

    private:
        // std::string figureName = "Hexagon";
        void fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data) override;
};
template<Number T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T>& figure);
template<Number T>
std::istream& operator>>(std::istream& is, Hexagon<T>& figure);