#include "FigureList.h"
#include "Figure.h"
#include "NumberConcept.h"
#include <memory>
template<Number T> FigureList<T>::FigureList(){
    this->size = 0;
    this->capacity = 10;
    
    // std::shared_ptr<std::shared_ptr<Figure<T>>> figures;
    this->figures = new T[this->capacity];
   
}

template<Number T> FigureList<T>::~FigureList(){
    this->size = 0;
    this->capacity = 0;
    // for (int i = 0;i < size; ++i){
    //     delete figures[i];
    // }
    // delete[] figures;
    // figures = nullptr;
}

template<Number T> void FigureList<T>::push_back(T figure){
    if (size + 2 > capacity){
        capacity *= 2;
       T* newFigures = new T[this->capacity];
        for (int i = 0; i < size; ++i){
            newFigures[i] = figures[i];
        }
        figures = newFigures;
    }

    figures[size++] = figure;

}

 template<Number T> T FigureList<T>::operator [](const int index) const{
    if (index >= size || index < 0){
        throw std::invalid_argument("Invalid index");
    }
    return figures[index];
 }

template<Number T> void FigureList<T>::remove(int index){
    if (index >= size || index < 0){
        throw std::invalid_argument("Invalid index");
    }
    for (int i = index; i < size; ++i){
        // delete figures[i];
        figures[i] = figures[i+1];
    }
    size--;
}

template<Number T> int FigureList<T>::getSize() const {
    return size;
}