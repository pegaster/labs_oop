#pragma once
#include "Figure.h"
#include <memory>
#include <vector>
#include "NumberConcept.h"
template<Number T> class FigureList{
    private:
        int size;
        int capacity;
        T* figures;
    public:
        FigureList();
        ~FigureList();
        void push_back(T figure);
        void remove(int index);
        int getSize() const;
        T operator [](const int index) const;
};