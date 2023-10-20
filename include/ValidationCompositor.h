#pragma once
#include <vector>
#include "ValidationHandler.h"
#include "Figure.h"
#include <stdexcept>

class ValidationCompositor {
    private:
        std::vector<const ValidationHandler *> validators;
    public:
        ValidationCompositor();
        void validate(const Figure &figure) const;
        virtual ~ValidationCompositor();
};