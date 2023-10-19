#pragma once
#include "ValidationHandler.h"
#include "Figure.h"
#include <stdexcept>

class HexagonValidationHandler : public ValidationHandler {
    public:
        void hadleRequest(const Figure &figure) const override;
        bool isAllowedTo(const Figure &figure) const override;
};