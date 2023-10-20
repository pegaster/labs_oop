#include "HexagonValidationHandler.h"
#include "Hexagon.h"
#include "Figure.h"
#include <math.h>

const double EPS = 1e-9;

bool HexagonValidationHandler::isAllowedTo(const Figure& fugure) const {
    try {
        dynamic_cast<const Hexagon &>(fugure);
    } catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

void HexagonValidationHandler::hadleRequest(const Figure& figure) const {
    for (int i = 0; i < 6; i++) {
        if (abs(figure.getPoints()[(i + 1) % 6] - figure.getPoints()[i]) <= EPS) {
            throw std::invalid_argument("The side with 0 length found");
        }
    }

    for (int i = 0; i < 6; i++) {
        if (isParallel(figure.getPoints()[(i + 1) % 6] - figure.getPoints()[i], figure.getPoints()[(i + 2) % 6] - figure.getPoints()[(i + 1) % 6])) {
            throw std::invalid_argument("neighbor sides are parallel");
        }
    }

    for (int i = 0; i < 6; i++) {
        const Point& p1 = figure.getPoints()[i];
        const Point& p2 = figure.getPoints()[(i + 1) % 6];
        for (int j = 0; j < 6; j++) {
            if (fabs(i - j) <= 1) {
                continue;
            }

            const Point& p3 = figure.getPoints()[j];
            const Point& p4 = figure.getPoints()[(j + 1) % 6];

            if (isCrossing(p1, p2, p3, p4)) {
                throw std::invalid_argument("crossing sides");
            }
        }
    }
}