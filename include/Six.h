#pragma once
#include <initializer_list>
#include <string>
#include <iostream>

class Six {
    friend class SixBuilder;
    private:
        size_t size;
        unsigned char *data;
        unsigned char* begin() const;
        unsigned char* end() const;
    public:
        Six();
        Six(const size_t & n, unsigned char t);
        Six(const std::initializer_list< unsigned char> &t);
        Six(const std::string &t);
        Six(const Six& other);
        Six(Six&& other) noexcept;
        virtual ~Six() noexcept;
        Six add(const Six& other) const;
        Six remove(const Six& other) const;
        bool equals(const Six& other) const;
        bool lessThan(const Six& other) const;
        bool greaterThan(const Six& other) const;
        std::string getData() const;
        size_t getSize() const;
        std::ostream &print(std::ostream& os) const;
        Six operator +(const Six& other) const;
        Six operator -(const Six& other) const;
        bool operator ==(const Six& other) const;
        bool operator >(const Six& other) const;
        bool operator <(const Six& other) const;
        Six & operator =(const Six& other);
        Six & operator =(Six&& other);
};

std::ostream &operator <<(std::ostream& os, const Six& object);
std::istream &operator >>(std::istream& is, Six& object);
