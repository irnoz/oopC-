#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<typename T>
class dynamic_array {
private:
    T *array;
    int capacity;
    int size_;

    int get_capacity() const;
    void resize(int);
    T& get_element_at(int) const;

public:
    dynamic_array();
    dynamic_array(int);
    ~dynamic_array();

    int size() const;
    void push_back(T);
    void pop_back();
    void push_at(int, T);
    void remove_at(int);
    void print();
    T& operator[](int index) const;
};

#endif // DYNAMICARRAY_H