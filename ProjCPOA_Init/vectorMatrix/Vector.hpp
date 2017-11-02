#include "Vector.h"

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

template <typename T,int N>
Vector<T,N> Vector<T,N>::operator*(const double scalaire) const{
    Vector<T,N> v_tmp;
    for(int i=0 ; i<N;i++){
        v_tmp[i] = (*this)[i] * scalaire;
    }
    return v_tmp;
}

//redefinition de l'operateur * pour pouvoir multiplier par un scalaire à droite
template <typename T,int N>
Vector<T,N> operator*(const double scalaire,const Vector<T,N>& v){
    Vector<T,N> v_tmp;
    for(int i=0 ; i<N;i++){
        v_tmp[i] = v[i] * scalaire;
    }
    return v_tmp;
}

template <typename T,int N>
Vector<T,N> Vector<T,N>::operator/(const double scalaire) const{
    Vector<T,N> v_tmp;
    for(int i=0 ; i<N;i++){
        v_tmp[i] = (*this)[i] / scalaire;
    }
    return v_tmp;
}

template <typename T,int N>
void Vector<T,N>::operator*=(const double scalaire){
    for(int i=0 ; i<N;i++){
        (*this)[i] *= scalaire;
    }
}

template <typename T,int N>
void Vector<T,N>::operator/=(const double scalaire){
    for(int i=0 ; i<N;i++){
        (*this)[i] /= scalaire;
    }
}
