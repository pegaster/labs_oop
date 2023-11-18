#pragma once

#include <vector>
template<class T>
class Allocator{
    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;

        Allocator()=default;
        pointer allocate(size_t size);
        void deallocate(pointer, size_t size);
        template <typename U, typename... Args> void construct(U *p, Args &&...args);
        void destroy(pointer p);

        template <typename U> struct rebind {
            using other = Allocator<U>;
        };

    private:
        std::vector<T> _memory;
};