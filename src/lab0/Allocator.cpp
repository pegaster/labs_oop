#include "Allocator.h"

template <class T> T* Allocator<T>::allocate(size_t size) {
    if (size <= 0) {
        throw std::invalid_argument("size must be more than 0");
    }
    size_type oldSize = _memory.size();
    _memory.resize(oldSize + size);
    return &_memory[oldSize];
}

template <class T> void Allocator<T>::deallocate(pointer, size_t size) {
    // тут надо освобождать память
}
template <class T> template <typename U, typename... Args> void Allocator<T>::construct(U *p, Args &&...args) {
    new (p) U(std::forward<Args>(args)...);
}

template <class T> void Allocator<T>::destroy(pointer p) {
    p->~T();
}