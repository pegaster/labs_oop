#include "ValidationCompositor.h"
#include "ValidationHandler.h"
#include "TriangleValidationHandler.h"
#include "HexagonValidationHandler.h"
#include "OctagonValidationHandler.h"

ValidationCompositor::ValidationCompositor() {
    validators.push_back(dynamic_cast<ValidationHandler *>(new TriangleValidationHandler()));
    validators.push_back(dynamic_cast<ValidationHandler *>(new HexagonValidationHandler()));
    validators.push_back(dynamic_cast<ValidationHandler *>(new OctagonValidationHandler()));
}

void ValidationCompositor::validate(const Figure &figure) const {
    for (const ValidationHandler* validator : validators) {
        if (validator->isAllowedTo(figure)) {
            validator->hadleRequest(figure);
        }
    }
}

ValidationCompositor::~ValidationCompositor() {
    for (const ValidationHandler* validator : validators) {
        delete validator;
    }
}