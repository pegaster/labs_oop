#include "ValidationCompositor.h"
#include "ValidationHandler.h"
#include "TriangleValidationHandler.h"
#include "OctagonValidationHandler.h"
#include "HexagonValidationHandler.h"

ValidationCompositor::ValidationCompositor() {
    validators.push_back(dynamic_cast<ValidationHandler *>(new TriangleValidationHandler()));
    validators.push_back(dynamic_cast<ValidationHandler *>(new OctagonValidationHandler()));
    validators.push_back(dynamic_cast<ValidationHandler *>(new HexagonValidationHandler()));
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