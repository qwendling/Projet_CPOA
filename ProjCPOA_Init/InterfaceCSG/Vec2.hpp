#include "Vec2.h"

template<typename T>
T produit_scalaire(const Vec2<T>& v1,const Vec2<T>& v2){
    return v1[0]*v2[0]+v1[1]*v2[1];
}

template<typename T>
T Vec2<T>::norme() const{
    return sqrt(produit_scalaire(*this,*this));
}
