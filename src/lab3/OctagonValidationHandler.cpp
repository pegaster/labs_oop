#include "OctagonValidationHandler.h"
#include "Octagon.h"
#include "Figure.h"
#include <math.h>

const double EPS = 1e-9;

bool OctagonValidationHandler::isAllowedTo(const Figure& fugure) const {
    try {
        dynamic_cast<const Octagon &>(fugure);
    } catch (const std::bad_cast &e) {
        return false;
    }
    return true;
}

void OctagonValidationHandler::hadleRequest(const Figure& figure) const {
    for (int i = 0; i < 8; i++) {
        if (abs(figure.getPoints()[(i + 1) % 8] - figure.getPoints()[i]) <= EPS) {
            throw std::invalid_argument("The side with 0 length found");
        }
    }

    for (int i = 0; i < 8; i++) {
        if (isParallel(figure.getPoints()[(i + 1) % 8] - figure.getPoints()[i], figure.getPoints()[(i + 2) % 8] - figure.getPoints()[(i + 1) % 8])) {
            throw std::invalid_argument("neighbor sides are parallel");
        }
    }

    for (int i = 0; i < 8; i++) {
        const Point& p1 = figure.getPoints()[i];
        const Point& p2 = figure.getPoints()[(i + 1) % 8];
        for (int j = 0; j < 8; j++) {
            if (fabs(i - j) <= 1) {
                continue;
            }

            const Point& p3 = figure.getPoints()[j];
            const Point& p4 = figure.getPoints()[(j + 1) % 8];

            if (isCrossing(p1, p2, p3, p4)) {
                throw std::invalid_argument("crossing sides");
            }
        }
    }
}