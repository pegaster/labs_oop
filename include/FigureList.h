#pragma once
#include <iostream>
#include "Figure.h"

class FigureList {
    protected:
        Figure **data_;
        size_t size_;
    public:
        FigureList();
        FigureList(size_t n);
        Figure*&operator[](size_t i);
        size_t getSize();
        ~FigureList();
};

std::istream& operator>>(std::istream& is, FigureList& dinList);