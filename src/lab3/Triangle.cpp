#include "Triangle.h"
#include "Point.h"
#include "ValidationCompositor.h"
#include <memory>
#include "NumberConcept.h"

template<Number T> Triangle<T>::Triangle(){
    this->points = std::shared_ptr<Point<T>>(new Point<T>[3]);
    this->figureName = "Triangle";
}

// std::string Triangle::getFigureName() const{
//     return figu
// }

template<Number T> Triangle<T>::Triangle(const std::shared_ptr<Point<T>> points){
    this->points = std::shared_ptr<Point<T>>(new Point<T>[3]);
    this->figureName = "Triangle";
    for (int i = 0; i < 3; ++i){
        this->points.get()[i] = points.get()[i];
    }
    ValidationCompositor<T> validator;
    validator.validate(dynamic_cast<Figure<T>&>(*this));
    

}

template<Number T> Triangle<T> Triangle<T>::create(const std::shared_ptr<Point<T>> points){
    return Triangle<T>{points};
}

template<Number T> Triangle<T>::Triangle(const Triangle<T>& other){
   this->points = std::shared_ptr<Point<T>>(new Point<T>[3]);
    for (int i = 0; i < 3; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
    //fillPoints(3,points, other.points);
}

template<Number T> Triangle<T>::Triangle(Triangle<T>&& other){
    this->points = other.points;
    // delete[] other.points;
    // other.points = nullptr;

}

template<Number T> Triangle<T>& Triangle<T>::operator=(Triangle<T>& other){
    //delete[] points;
   this->points = std::shared_ptr<Point<T>>(new Point<T>[3]);
    for (int i = 0; i < 3; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
    // fillPoints(3,points,other.points);
    return *this;
}

template<Number T> Triangle<T>& Triangle<T>::operator=(Triangle<T>&& other){
    this->points = other.points;
    // delete[] other.points;
    // other.points=nullptr;
    return *this;
}

template<Number T> bool Triangle<T>::operator==(Triangle<T>& other){
    for (int i = 0; i < 3; ++i){
        int flag = 0;
        for (int j =0; j < 3; ++j){
            if ((this->points.get()[i].getX() == other.points.get()[i].getX()) && (this->points.get()[i].getY() == other.points.get()[i].getY())){
                flag = 1;
            }
        }
        if (flag == 0){
            return false;
        }
    }
    return true;
}

template<Number T> Figure<T>& Triangle<T>::operator=(const Figure<T>&& other){
    try{
        const Triangle<T>&& other_pentagon = dynamic_cast<const Triangle<T>&&>(other);
        return *this = other_pentagon;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Triangle");

    }
    
}
template<Number T> Figure<T>& Triangle<T>::operator=(const Figure<T>& other){
    try{
        const Triangle<T>& other_pentagon = dynamic_cast<const Triangle<T>&>(other);
        return *this = other_pentagon;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Triangle");

    }
}

template<Number T> bool Triangle<T>::operator==(const Figure<T>& other){
    try{
        const Triangle<T>& other_pentagon = dynamic_cast<const Triangle<T>&>(other);
        return *this== other_pentagon;
    }
    catch(const std::bad_cast &e){
        return false;
    }
}

template<Number T> Point<T> Triangle<T>::center()const{
    T Xsum = 0;
    T Ysum = 0;
    for(int i = 0; i < 3; ++i){
        Xsum += this->points.get()[i].getX();
        Ysum += this->points.get()[i].getY();
    }
    Point<T> center;
    center.setX(Xsum / 3); 
    center.setY(Ysum / 3);

    return center;

}

template<Number T> Triangle<T>::operator double() const{
    double s = 0;
    for (int i = 0; i < 3; i++) {
        s += this->points.get()[i].getX() * this->points.get()[(i + 1) % 3].getY() - this->points.get()[i].getY() * this->points.get()[(i + 1) % 3].getX();
    }
    return fabs(s / 2);
}


template<Number T>void Triangle<T>::fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data){
     for (int i = 0; i < 3; ++ i){
        res[i] = data[i];
    }
}


template<Number T> std::ostream& Triangle<T>::print(std::ostream& os) const{
    for (int i = 0; i < 3; ++i){
        os << this->points.get()[i] << "\n";
    }
    return os;
    
}
template<Number T> std::istream& Triangle<T>::read(std::istream& is){
    for (int i = 0; i < 3; ++i){
        is >> this->points.get()[i];
    }
    return is;
}

template<Number T> std::ostream& operator<<(std::ostream& os, const Triangle<T>& figure){
    return figure.print(std::cout);
}

template<Number T> std::istream& operator>>(std::istream& is, Triangle<T>& figure){
    return figure.read(std::cin);
}