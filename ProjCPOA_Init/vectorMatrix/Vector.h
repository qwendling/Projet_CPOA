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
    void operator+=(const Vector<T,N>& v2);
    void operator-=(const Vector<T,N>& v2);
};

template <typename T,int N>
Vector<T,N> Vector<T,N>::operator+(const Vector<T,N>& v2) const{
    Vector<T,N> v_tmp;
    for(int i=0 ; i<N;i++){
        v_tmp[i] = (*this)[i] + v2[i];
    }
    return v_tmp;
}

template <typename T,int N>
Vector<T,N> Vector<T,N>::operator-(const Vector<T,N>& v2) const{
    Vector<T,N> v_tmp;
    for(int i=0 ; i<N;i++){
        v_tmp[i] = (*this)[i] - v2[i];
    }
    return v_tmp;
}

template <typename T,int N>
void Vector<T,N>::operator+=(const Vector<T,N>& v2){
    for(int i=0 ; i<N;i++){
        (*this)[i] += v2[i];
    }
}

template <typename T,int N>
void Vector<T,N>::operator-=(const Vector<T,N>& v2){
    for(int i=0 ; i<N;i++){
        (*this)[i] -= v2[i];
    }
}

#endif
