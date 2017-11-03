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

template <typename T,int N>
T Vector<T,N>::operator*(const Vector<T,N>& v2) const{
    T result(0);
    for(int i =0;i<N;i++){
        result += (*this)[i]*v2[i];
    }
    return result;
}

template <typename T,int N>
auto vect(Vector<T,N> v1,Vector<T,N> v2) -> typename std::enable_if<N == 2,T>::type{
    return v1[0]*v2[1]-v1[1]*v2[0];
}

template <typename T,int N>
auto vect(Vector<T,N> v1,Vector<T,N> v2) -> typename std::enable_if<N == 3,Vector<T,N>>::type{
    Vector<T,N> tmp{v1[1]*v2[2]-v1[2]*v2[1],v1[2]*v2[0]-v1[0]*v2[2],v1[0]*v2[1]-v1[1]*v2[0]};
    return tmp;
}
