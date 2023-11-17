#include "Figure.h"
#include "NumberConcept.h"

template <Number T> Figure<T>::Figure(std::string figureName){
    this->figureName = figureName;
}

template <Number T> Figure<T>::~Figure(){
    this->figureName = "";
    // delete[] points;
    // points = nullptr;

}

template <Number T> Figure<T>::Figure(){
    this->figureName = "";
    this->points = nullptr;
}

template <Number T> std::shared_ptr<Point<T>> Figure<T>::getPoints() const{
    return this->points;
}

template <Number T> std::string Figure<T>::getFigureName() const{
    return this->figureName;
}

template<Number T> std::ostream& operator<<(std::ostream& os, const Figure<T>& figure){
    return figure.print(os);
}

template< Number T>std::istream& operator>>(std::istream& is, Figure<T>& figure){
    return figure.read(is);
}
