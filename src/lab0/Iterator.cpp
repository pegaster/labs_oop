#include "DynamicArray.h"

template<typename T, typename Allocator> ArrayIterator<T, Allocator>::ArrayIterator(PointerType ptr){
    this->ptr = ptr;
}

template<typename T, typename Allocator> ArrayIterator<T, Allocator>& ArrayIterator<T, Allocator>::operator++(){
    this->ptr++;
    return *this;
}


template<typename T, typename Allocator> ArrayIterator<T, Allocator> ArrayIterator<T, Allocator>::operator++(int){
    ArrayIterator<T, Allocator> itr = *this;
    ++(*this);
    return itr;
}

template<typename T, typename Allocator> ArrayIterator<T, Allocator>& ArrayIterator<T, Allocator>::operator--(){
    this->ptr--;
    return *this;
}

template<typename T, typename Allocator> ArrayIterator<T, Allocator> ArrayIterator<T, Allocator>::operator--(int){
    ArrayIterator<T, Allocator> itr = *this;
    --(*this);
    return itr;
}

template<typename T, typename Allocator> T& ArrayIterator<T, Allocator>::operator[](int index){
    return *(this->ptr + index);

}

template<typename T, typename Allocator> T* ArrayIterator<T, Allocator>::operator->(){
    this->ptr;
}

template<typename T, typename Allocator> T& ArrayIterator<T, Allocator>::operator*(){
    return *ptr;
}

template<typename T, typename Allocator> bool ArrayIterator<T, Allocator>::operator==(const ArrayIterator<T, Allocator>& other) const {
    return this->ptr == other.ptr;
}

template<typename T, typename Allocator> bool ArrayIterator<T, Allocator>::operator!=(const ArrayIterator<T, Allocator>& other) const {
    return this->ptr != other.ptr;
}