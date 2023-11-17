#pragma once
#include "Figure.h"
#include "NumberConcept.h"

template<Number T> class Triangle : public Figure<T>{
    template <Number U> friend std::ostream& operator<<(std::ostream& os, const Triangle<U>& figure);
    template<Number U> friend std::istream& operator>>(std::istream& is, Triangle<U>& figure);
    public:
        Triangle();
        Triangle(const std::shared_ptr<Point<T>> points);
        Triangle(const Triangle<T>& other);
        Triangle(Triangle<T>&& other);

        virtual ~Triangle() = default;

        // std::string getFigureName() const;
        // Point* getPoints() const;
        static Triangle<T> create(const std::shared_ptr<Point<T>> points);
        
        virtual std::ostream& print(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;

        virtual operator double() const override;
        virtual Point<T> center() const override;
        
        Triangle<T>& operator=(Triangle<T>& other);
        Triangle<T>& operator=(Triangle<T>&& other);
        bool operator==(Triangle<T>& other);

        virtual Figure<T>& operator=(const Figure<T>&& other) override;
        virtual Figure<T>& operator=(const Figure<T>& other) override;
        virtual bool operator==(const Figure<T>& other) override;

    private:
        // std::string figureName = "Triangle";
        void fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data) override;
};
template<Number T>
std::ostream& operator<<(std::ostream& os, const Triangle<T>& figure);
template<Number T>
std::istream& operator>>(std::istream& is, Triangle<T>& figure);