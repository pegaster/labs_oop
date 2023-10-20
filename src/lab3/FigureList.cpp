#include "FigureList.h"
#include "Triangle.h"
#include "Octagon.h"
#include "Hexagon.h"
#include <string>

FigureList::FigureList() {
    size_ = 0;
    data_ = nullptr;
}

FigureList::FigureList(size_t n) {
    if (n <= 0) {
        throw std::invalid_argument("Invalid size");
    }
    size_ = n;
    data_ = new Figure*[size_];
}

Figure*& FigureList::operator[](size_t i) {
    if (i < 0 || i >= size_) {
        throw std::invalid_argument("Invalid index");
    }
    return data_[i];
}

size_t FigureList::getSize() {
    return size_;
}

FigureList::~FigureList() {
    for (size_t i = 0; i < size_; i++) {
        delete data_[i];
    }
    delete[] data_;
}

std::istream& operator>>(std::istream& is, FigureList& FigureList) {
    for (size_t i = 0; i < FigureList.getSize(); i++) {
        std::string figureFigureype;
        is >> figureFigureype;
        if (figureFigureype == "triangle" || figureFigureype == "Triangle") {
            FigureList[i] = new Triangle();
        } else if (figureFigureype == "octagon" || figureFigureype == "Octagon") {
            FigureList[i] = new Octagon();
        } else if (figureFigureype == "hexagon" || figureFigureype == "Hexagon") {
            FigureList[i] = new Hexagon();
        } else {
            throw std::invalid_argument("Invalid figure type");
        }

        is >> *FigureList[i];
    }
    return is;
}