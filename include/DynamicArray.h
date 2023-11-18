#pragma once
#include <memory>
#include <iostream>

template<typename T, typename Allocator = std::allocator<T> > class ArrayIterator {
    public:
        using ValueType = T;
        using PointerType = ValueType*;
        using ReferenceType = ValueType&;
        ArrayIterator(PointerType ptr);
        ArrayIterator& operator++();
        ArrayIterator operator++(int);
        ArrayIterator& operator--();
        ArrayIterator operator--(int);
        ReferenceType operator[](int index);
        PointerType operator->();
        ReferenceType operator*();
        bool operator==(const ArrayIterator& other) const;
        bool operator!=(const ArrayIterator& other) const;
    private:
        PointerType ptr;
};

template<typename T, typename Allocator = std::allocator<T> >
class DynamicArray{
    public:
        using ValueType = T;
        DynamicArray();
        DynamicArray(int size);
        DynamicArray(const DynamicArray<T, Allocator > &v);
        DynamicArray(const DynamicArray<T, Allocator> &&v);
        
        T operator[](int index);
        int getSize() const;
        void push_back(T element);

        void reserve(int newCapacity);
        ArrayIterator<T, Allocator> begin();
        const ArrayIterator<T, Allocator> cbegin() const;
        ArrayIterator<T, Allocator> end();
        const ArrayIterator<T, Allocator> cend() const;
        ~DynamicArray();

    private:
        T* data;
        int size;
        int capacity;
        Allocator allocator;
};

