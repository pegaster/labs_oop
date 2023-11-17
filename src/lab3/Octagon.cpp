#include "Octagon.h"
#include "Point.h"
#include "ValidationCompositor.h"
#include <memory>
#include "NumberConcept.h"

template<Number T> Octagon<T>::Octagon(){
    this->points = std::shared_ptr<Point<T>>(new Point<T>[8]);
    this->figureName = "Octagon";
}

// std::string Octagon::getFigureName() const{
//     return figu
// }

template<Number T> Octagon<T>::Octagon(const std::shared_ptr<Point<T>> points){
    this->points = std::shared_ptr<Point<T>>(new Point<T>[8]);
    this->figureName = "Octagon";
    for (int i = 0; i < 8; ++i){
        this->points.get()[i] = points.get()[i];
    }
    ValidationCompositor<T> validator;
    validator.validate(dynamic_cast<Figure<T>&>(*this));
    

}

template<Number T> Octagon<T> Octagon<T>::create(const std::shared_ptr<Point<T>> points){
    return Octagon<T>{points};
}

template<Number T> Octagon<T>::Octagon(const Octagon<T>& other){
   this->points = std::shared_ptr<Point<T>>(new Point<T>[8]);
    for (int i = 0; i < 8; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
    //fillPoints(8,points, other.points);
}

template<Number T> Octagon<T>::Octagon(Octagon<T>&& other){
    this->points = other.points;
    // delete[] other.points;
    // other.points = nullptr;

}

template<Number T> Octagon<T>& Octagon<T>::operator=(Octagon<T>& other){
    //delete[] points;
   this->points = std::shared_ptr<Point<T>>(new Point<T>[8]);
    for (int i = 0; i < 8; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
    // fillPoints(8,points,other.points);
    return *this;
}

template<Number T> Octagon<T>& Octagon<T>::operator=(Octagon<T>&& other){
    this->points = other.points;
    // delete[] other.points;
    // other.points=nullptr;
    return *this;
}

template<Number T> bool Octagon<T>::operator==(Octagon<T>& other){
    for (int i = 0; i < 8; ++i){
        int flag = 0;
        for (int j =0; j < 8; ++j){
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

template<Number T> Figure<T>& Octagon<T>::operator=(const Figure<T>&& other){
    try{
        const Octagon<T>&& other_pentagon = dynamic_cast<const Octagon<T>&&>(other);
        return *this = other_pentagon;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Octagon");

    }
    
}
template<Number T> Figure<T>& Octagon<T>::operator=(const Figure<T>& other){
    try{
        const Octagon<T>& other_pentagon = dynamic_cast<const Octagon<T>&>(other);
        return *this = other_pentagon;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Octagon");

    }
}

template<Number T> bool Octagon<T>::operator==(const Figure<T>& other){
    try{
        const Octagon<T>& other_pentagon = dynamic_cast<const Octagon<T>&>(other);
        return *this== other_pentagon;
    }
    catch(const std::bad_cast &e){
        return false;
    }
}

template<Number T> Point<T> Octagon<T>::center()const{
    T Xsum = 0;
    T Ysum = 0;
    for(int i = 0; i < 8; ++i){
        Xsum += this->points.get()[i].getX();
        Ysum += this->points.get()[i].getY();
    }
    Point<T> center;
    center.setX(Xsum / 8); 
    center.setY(Ysum / 8);

    return center;

}

template<Number T> Octagon<T>::operator double() const{
    double s = 0;
    for (int i = 0; i < 8; i++) {
        s += this->points.get()[i].getX() * this->points.get()[(i + 1) % 8].getY() - this->points.get()[i].getY() * this->points.get()[(i + 1) % 8].getX();
    }
    return fabs(s / 2);
}


template<Number T>void Octagon<T>::fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data){
     for (int i = 0; i < 8; ++ i){
        res[i] = data[i];
    }
}


template<Number T> std::ostream& Octagon<T>::print(std::ostream& os) const{
    for (int i = 0; i < 8; ++i){
        os << this->points.get()[i] << "\n";
    }
    return os;
    
}
template<Number T> std::istream& Octagon<T>::read(std::istream& is){
    for (int i = 0; i < 8; ++i){
        is >> this->points.get()[i];
    }
    return is;
}

template<Number T> std::ostream& operator<<(std::ostream& os, const Octagon<T>& figure){
    return figure.print(std::cout);
}

template<Number T> std::istream& operator>>(std::istream& is, Octagon<T>& figure){
    return figure.read(std::cin);
}