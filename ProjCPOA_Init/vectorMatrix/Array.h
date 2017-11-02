#ifndef ARRAY_H
#define ARRAY_H

template <typename T, int N>
class Array{
    public:
        Array();
        Array(std::initializer_list<T> inil);
        T operator[](const int index) const;
        T& operator[](const int index);
        void operator=(const Array<T,N>& a);
        bool operator==(const Array<T,N>& a) const;
        bool operator!=(const Array<T,N>& a) const;
        const T* get_ptr() const;
        void swap(Array<T,N>& a);
    protected:
        T data[N];

};

#include "Array.hpp"

#endif
