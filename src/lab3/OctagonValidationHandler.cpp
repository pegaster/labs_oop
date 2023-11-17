#include "OctagonValidationHandler.h"
#include "Octagon.h"
#include "Figure.h"

// const double EPS = 1e-9;

template<class T> bool OctagonValidationHandler<T>::isAllowed(const Figure<T>& fugure) const {
    try {
        dynamic_cast<const Octagon<T> &>(fugure);
    } catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

template<class T> void OctagonValidationHandler<T>::validate(const Figure<T>& figure) const {
    for (int i = 0; i < 8; i++) {
        if (abs(figure.getPoints().get()[(i + 1) % 8] - figure.getPoints().get()[i]) <= 1e-9) {
            throw std::invalid_argument("The side with 0 length found(");
        }
    }

    for (int i = 0; i < 8; i++) {
        if (isParalel(figure.getPoints().get()[(i + 1) % 8] - figure.getPoints().get()[i], figure.getPoints().get()[(i + 2) % 5] - figure.getPoints().get()[(i + 1) % 5])) {
            throw std::invalid_argument("neighbor sides are parallel");
        }
    }

}
