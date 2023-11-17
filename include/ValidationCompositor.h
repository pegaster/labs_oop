#pragma once
#include "HexagonValidationHandler.h"
#include "OctagonValidationHandler.h"
#include "TriangleValidationHandler.h"
#include "ValidationHandler.h"
#include "Figure.h"
#include <vector>


template<class T>class ValidationCompositor{
    private:
        std::vector<std::shared_ptr<ValidationHandler<T>>> validations;

    public:
    ValidationCompositor();
    virtual ~ValidationCompositor() = default;
    void validate(Figure<T>& figure) const;
};