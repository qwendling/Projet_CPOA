#ifndef VECTOR_H
#define VECTOR_H
#include "Array.h"

template <typename T,int N>
class Vector : public Array<T,N>{
public:
    Vector() : Array<T,N>(){}
    Vector(std::initializer_list<T> inil) : Array<T,N>(inil){}

    Vector<T,N> operator+(const Vector<T,N>& v2) const;
    Vector<T,N> operator-(const Vector<T,N>& v2) const;
    T operator*(const Vector<T,N>& v2) const;
    Vector<T,N> operator*(const double scalaire) const;
    Vector<T,N> operator/(const double scalaire) const;

    void operator+=(const Vector<T,N>& v2);
    void operator-=(const Vector<T,N>& v2);
    void operator*=(const double scalaire);
    void operator/=(const double scalaire);
};

#include "Vector.hpp"

#endif
