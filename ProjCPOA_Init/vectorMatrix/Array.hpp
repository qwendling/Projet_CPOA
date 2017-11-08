#include "Array.h"
#include <iostream>
#include <assert.h>

template <typename T, int N>
Array<T,N>::Array(){
    for(int i=0;i<N;i++){
        data[i]=T();
    }
}

template <typename T, int N>
Array<T,N>::Array(std::initializer_list<T> inil){
    assert(inil.size() <= N);
    int j=0;
    for(T x: inil)
        data[j++]=x;
}


template <typename T, int N>
T Array<T,N>::operator[](const int index) const {
    return data[index];
}

template <typename T, int N>
T& Array<T,N>::operator[](const int index){
    return data[index];
}

template <typename T, int N>
bool Array<T,N>::operator==(const Array<T,N>& a) const{
    for(int i=0;i<N;i++){
        if(data[i] != a[i])
            return false;
    }
    return true;
}

template <typename T, int N>
bool Array<T,N>::operator!=(const Array<T,N>& a) const{
    return !(*this==a);
}

template <typename T, int N>
void Array<T,N>::operator=(const Array<T,N>& a){
    for(int i=0;i<N;i++){
        data[i] = a[i];
    }
}

template <typename T,int N>
const T* Array<T,N>::get_ptr() const{
    return data;
}

template <typename T,int N>
void Array<T,N>::swap(Array<T,N>& a){
    //variable temporaire pour la copie des tableaux
    T d_tmp;

    for(int i=0;i<N;i++){
        d_tmp = data[i];
        data[i] = a[i];
        a[i] = d_tmp;
    }


}

template <typename T,int N>
std::ostream &operator<<(std::ostream &out,const Array<T,N>& a){
    out << '{';
    out << a[0];
    for(int i=1;i<N;i++){
        out << ", " << a[i];
    }
    out << '}';
    return out;
}
