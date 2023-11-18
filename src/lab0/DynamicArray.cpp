#include "DynamicArray.h"

template<typename T, typename Allocator> DynamicArray<T, Allocator>::DynamicArray(){
    this->size = 0;
    this->capacity = 0;
    this->data = nullptr;
}


template<typename T, typename Allocator> DynamicArray<T, Allocator>::DynamicArray(int size){
    this->size = 0;
    this->capacity = size;
    this->data = this->allocator.allocate(size);
}


template<typename T, typename Allocator> DynamicArray<T, Allocator>::DynamicArray(const DynamicArray<T, Allocator > &v){
    this->size = v.size;
    this->capacity = this->size;       
    this->data = this->allocator.allocate(size);
    for (int i = 0; i < v.size(); ++i){
        this->data[i] = v[i];
    }
}


template<typename T, typename Allocator> DynamicArray<T, Allocator>::DynamicArray(const DynamicArray<T, Allocator> &&v){
    this->size = v.size;
    this->capacity = this->size;
    this->data = v.data;
    v.data = nullptr;
}


template<typename T, typename Allocator> T DynamicArray<T, Allocator>::operator[](int index){
     if (index < 0 || index >= this->size){
        throw  std::out_of_range("Index out of range");
    }
    return this->data[index];
}

template<typename T, typename Allocator> int DynamicArray<T, Allocator>::getSize() const {
    return this->size;
}

template<typename T, typename Allocator> void DynamicArray<T, Allocator>::push_back(T element){
    if (this->capacity == 0){
        this->capacity = 1;
        this->size = 0;
        this->data = this->allocator.allocate(this->size);
    }

    if (this->size == this->capacity){
        this->capacity *= 2;
        this->reserve(this->capacity);
    }
            
    this->data[size] = element;
    this->size++;
}

template<typename T, typename Allocator> void DynamicArray<T, Allocator>::reserve(int newCapacity){
    if (newCapacity > this->capacity){
        T* newData = this->allocator.allocate(size);
        for (int i = 0; i < this->size;++i){
            newData[i] = this->data[i];
        }
        this->allocator.deallocate(this->data, this->capacity);
        this->data = newData;
    }
}

template<typename T, typename Allocator>  ArrayIterator<T, Allocator> DynamicArray<T, Allocator>::begin(){
    return ArrayIterator<T, Allocator>(this->data);
}

template<typename T, typename Allocator>  ArrayIterator<T, Allocator> DynamicArray<T, Allocator>::end(){
    return ArrayIterator<T, Allocator>(this->data + this->size);
}

template<typename T, typename Allocator>  const ArrayIterator<T, Allocator> DynamicArray<T, Allocator>::cbegin()const{
    return  ArrayIterator<T, Allocator>(this->data);
}

template<typename T, typename Allocator> const ArrayIterator<T, Allocator> DynamicArray<T, Allocator>::cend() const{
    return  ArrayIterator<T, Allocator>(this->data + this->size);
}

template<typename T, typename Allocator> DynamicArray<T, Allocator>::~DynamicArray(){
   allocator.deallocate(this->data, this->capacity);
}