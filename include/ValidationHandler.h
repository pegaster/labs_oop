#pragma once
#include <Figure.h>
#include <vector>

template< class T>class ValidationHandler{
    public:
        virtual void validate(const Figure<T>& figure1) const = 0;
        virtual bool isAllowed(const Figure<T>& fugure) const = 0;
};