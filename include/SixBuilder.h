#pragma once
#include "Six.h"
#include <string>

class SixBuilder {
    private:
        Six object;
    
    public:
        SixBuilder() = default;

        SixBuilder &data(std::string value);

        SixBuilder &size(size_t value);

        Six build();
};