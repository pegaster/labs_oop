#pragma once
#include "Figure.h"

class ValidationHandler {
    public:
        virtual void hadleRequest(const Figure &figure) const = 0;
        virtual bool isAllowedTo(const Figure &figure) const = 0;
        virtual ~ValidationHandler() = default;
};