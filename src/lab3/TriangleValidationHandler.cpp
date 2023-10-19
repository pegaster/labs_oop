#include "TriangleValidationHandler.h"
#include "Triangle.h"
#include "Figure.h"


void TriangleValidationHandler::hadleRequest(const Figure &figure) const {
    for (int i = 0; i < 3; i++) {
        if (abs(figure.getPoints()[(i + 1) % 3] - figure.getPoints()[i]) <= epsilon) {
            throw std::invalid_argument("neighbor sides are parallel");
        }
    }

    for (int i = 0; i < 3; i++) {
        if (isParallel(figure.getPoints()[(i + 1) % 3] - figure.getPoints()[i], figure.getPoints()[(i + 2) % 3] - figure.getPoints()[(i + 1) % 3])) {
            throw std::invalid_argument("neighbor sides are parallel");
        }
    }
}

bool TriangleValidationHandler::isAllowedTo(const Figure &figure) const {
    try {
        dynamic_cast<const Triangle &>(figure);
    } catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}