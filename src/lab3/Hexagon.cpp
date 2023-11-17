#include "Hexagon.h"
#include "Point.h"
#include "ValidationCompositor.h"
#include <memory>
#include "NumberConcept.h"

template<Number T> Hexagon<T>::Hexagon(){
    this->points = std::shared_ptr<Point<T>>(new Point<T>[6]);
    this->figureName = "Hexagon";
}

// std::string Hexagon::getFigureName() const{
//     return figu
// }

template<Number T> Hexagon<T>::Hexagon(const std::shared_ptr<Point<T>> points){
    this->points = std::shared_ptr<Point<T>>(new Point<T>[6]);
    this->figureName = "Hexagon";
    for (int i = 0; i < 6; ++i){
        this->points.get()[i] = points.get()[i];
    }
    ValidationCompositor<T> validator;
    validator.validate(dynamic_cast<Figure<T>&>(*this));
    

}

template<Number T> Hexagon<T> Hexagon<T>::create(const std::shared_ptr<Point<T>> points){
    return Hexagon<T>{points};
}

template<Number T> Hexagon<T>::Hexagon(const Hexagon<T>& other){
   this->points = std::shared_ptr<Point<T>>(new Point<T>[6]);
    for (int i = 0; i < 6; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
    //fillPoints(6,points, other.points);
}

template<Number T> Hexagon<T>::Hexagon(Hexagon<T>&& other){
    this->points = other.points;
    // delete[] other.points;
    // other.points = nullptr;

}

template<Number T> Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>& other){
    //delete[] points;
   this->points = std::shared_ptr<Point<T>>(new Point<T>[6]);
    for (int i = 0; i < 6; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
    // fillPoints(6,points,other.points);
    return *this;
}

template<Number T> Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& other){
    this->points = other.points;
    // delete[] other.points;
    // other.points=nullptr;
    return *this;
}

template<Number T> bool Hexagon<T>::operator==(Hexagon<T>& other){
    for (int i = 0; i < 6; ++i){
        int flag = 0;
        for (int j =0; j < 6; ++j){
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

template<Number T> Figure<T>& Hexagon<T>::operator=(const Figure<T>&& other){
    try{
        const Hexagon<T>&& other_pentagon = dynamic_cast<const Hexagon<T>&&>(other);
        return *this = other_pentagon;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Hexagon");

    }
    
}
template<Number T> Figure<T>& Hexagon<T>::operator=(const Figure<T>& other){
    try{
        const Hexagon<T>& other_pentagon = dynamic_cast<const Hexagon<T>&>(other);
        return *this = other_pentagon;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Hexagon");

    }
}

template<Number T> bool Hexagon<T>::operator==(const Figure<T>& other){
    try{
        const Hexagon<T>& other_pentagon = dynamic_cast<const Hexagon<T>&>(other);
        return *this== other_pentagon;
    }
    catch(const std::bad_cast &e){
        return false;
    }
}

template<Number T> Point<T> Hexagon<T>::center()const{
    T Xsum = 0;
    T Ysum = 0;
    for(int i = 0; i < 6; ++i){
        Xsum += this->points.get()[i].getX();
        Ysum += this->points.get()[i].getY();
    }
    Point<T> center;
    center.setX(Xsum / 6); 
    center.setY(Ysum / 6);

    return center;

}

template<Number T> Hexagon<T>::operator double() const{
    double s = 0;
    for (int i = 0; i < 6; i++) {
        s += this->points.get()[i].getX() * this->points.get()[(i + 1) % 6].getY() - this->points.get()[i].getY() * this->points.get()[(i + 1) % 6].getX();
    }
    return fabs(s / 2);
}


template<Number T>void Hexagon<T>::fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data){
     for (int i = 0; i < 6; ++ i){
        res[i] = data[i];
    }
}


template<Number T> std::ostream& Hexagon<T>::print(std::ostream& os) const{
    for (int i = 0; i < 6; ++i){
        os << this->points.get()[i] << "\n";
    }
    return os;
    
}
template<Number T> std::istream& Hexagon<T>::read(std::istream& is){
    for (int i = 0; i < 6; ++i){
        is >> this->points.get()[i];
    }
    return is;
}

template<Number T> std::ostream& operator<<(std::ostream& os, const Hexagon<T>& figure){
    return figure.print(std::cout);
}

template<Number T> std::istream& operator>>(std::istream& is, Hexagon<T>& figure){
    return figure.read(std::cin);
}