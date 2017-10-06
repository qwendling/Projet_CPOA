#ifndef ARRAY_H
#define ARRAY_H

template <typename T, int N>
class Array{
    public:
        Array();
        T operator[](const int index) const;
        T& operator[](const int index);
        const T* get_ptr() const;
    protected:
        T data[N];

};

#include "Array.hpp"

#endif
