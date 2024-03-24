#include "dynamic_array.h"
#include <iostream>
#include <stdexcept>

template<typename T>
dynamic_array<T>::dynamic_array() {
    size_ = 0;
    capacity = 5;
    array = new T[capacity];
}

template<typename T>
dynamic_array<T>::dynamic_array(int size) {
    size_ = size;
    capacity = size * 2;
    array = new T[capacity];
}

template<typename T>
dynamic_array<T>::~dynamic_array() {
    delete[] array;
}

template<typename T>
int dynamic_array<T>::get_capacity() const {
    return this->capacity;
}

template<typename T>
void dynamic_array<T>::resize(int new_capacity) {
    T *temp = new T[new_capacity];
    for (int i = 0; i < size_; ++i) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    capacity = new_capacity;
}
template<typename T> 
T& dynamic_array<T>::get_element_at(int idx) const {
    if (idx < 0 || idx >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return *(array + idx);
}

template<typename T>
int dynamic_array<T>::size() const {
    return this->size_;
}

template<typename T>
void dynamic_array<T>::push_back(T value) {
    if (size_ == capacity) {
        resize(capacity * 2);
    }
    array[size_++] = value;
}

template<typename T>
void dynamic_array<T>::pop_back() {
    if (size_ > 0) {
        --size_;
    } else {
        throw std::out_of_range("Array is empty. Please add elements before trying to remove them.");
    }
}

template<typename T>
void dynamic_array<T>::push_at(int idx, T value) {
    if (idx < 0 || idx > size_) {
        throw std::out_of_range("Index out of range");
    }
    if (size_ == capacity) {
        resize(capacity * 2);
    }
    for (int i = size_; i > idx; i--) {
        array[i] = array[i - 1];
    }
    array[idx] = value;
    ++size_;
}

template<typename T>
void dynamic_array<T>::remove_at(int idx) {
    if (idx < 0 || idx >= size_) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = idx; i < size_ - 1; ++i) {
        array[i] = array[i + 1];
    }
    --size_;
}

template<typename T>
void dynamic_array<T>::print() {
    for (int i = 0; i < size_; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
T& dynamic_array<T>::operator[](int idx) const {
    if (idx < 0 || idx >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return get_element_at(idx);
}

template class dynamic_array<int>;
template class dynamic_array<float>;
template class dynamic_array<double>;
template class dynamic_array<char>;