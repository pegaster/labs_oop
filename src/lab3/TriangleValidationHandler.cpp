#include "TriangleValidationHandler.h"
#include "Triangle.h"
#include "Figure.h"

const double EPS = 1e-9;

bool TriangleValidationHandler::isAllowedTo(const Figure& fugure) const {
    try {
        dynamic_cast<const Triangle &>(fugure);
    } catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

void TriangleValidationHandler::hadleRequest(const Figure& figure) const {
    for (int i = 0; i < 3; i++) {
        if (abs(figure.getPoints()[(i + 1) % 3] - figure.getPoints()[i]) <= EPS) {
            throw std::invalid_argument("The side with 0 length found");
        }
    }

    for (int i = 0; i < 3; i++) {
        if (isParallel(figure.getPoints()[(i + 1) % 3] - figure.getPoints()[i], figure.getPoints()[(i + 2) % 3] - figure.getPoints()[(i + 1) % 3])) {
            throw std::invalid_argument("neighbor sides are parallel");
        }
    }
}