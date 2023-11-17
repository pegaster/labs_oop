#pragma once
#include "Figure.h"
#include "NumberConcept.h"

template<Number T> class Octagon : public Figure<T>{
    template <Number U> friend std::ostream& operator<<(std::ostream& os, const Octagon<U>& figure);
    template<Number U> friend std::istream& operator>>(std::istream& is, Octagon<U>& figure);
    public:
        Octagon();
        Octagon(const std::shared_ptr<Point<T>> points);
        Octagon(const Octagon<T>& other);
        Octagon(Octagon<T>&& other);

        virtual ~Octagon() = default;

        // std::string getFigureName() const;
        // Point* getPoints() const;
        static Octagon<T> create(const std::shared_ptr<Point<T>> points);
        
        virtual std::ostream& print(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;

        virtual operator double() const override;
        virtual Point<T> center() const override;
        
        Octagon<T>& operator=(Octagon<T>& other);
        Octagon<T>& operator=(Octagon<T>&& other);
        bool operator==(Octagon<T>& other);

        virtual Figure<T>& operator=(const Figure<T>&& other) override;
        virtual Figure<T>& operator=(const Figure<T>& other) override;
        virtual bool operator==(const Figure<T>& other) override;

    private:
        // std::string figureName = "Octagon";
        void fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data) override;
};
template<Number T>
std::ostream& operator<<(std::ostream& os, const Octagon<T>& figure);
template<Number T>
std::istream& operator>>(std::istream& is, Octagon<T>& figure);