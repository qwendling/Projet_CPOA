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

class Vec2i :public Vector<int,2>{
public:
    Vec2i() : Vector<int,2>(){}
    Vec2i(std::initializer_list<int> inil) : Vector<int,2>(inil){}
};
class Vec3i :public Vector<int,3>{
public:
    Vec3i() : Vector<int,3>(){}
    Vec3i(std::initializer_list<int> inil) : Vector<int,3>(inil){}
};
class Vec4i :public Vector<int,4>{
public:
    Vec4i() : Vector<int,4>(){}
    Vec4i(std::initializer_list<int> inil) : Vector<int,4>(inil){}
};
class Vec2f :public Vector<float,2>{
public:
    Vec2f() : Vector<float,2>(){}
    Vec2f(std::initializer_list<float> inil) : Vector<float,2>(inil){}
};
class Vec3f :public Vector<float,3>{
public:
    Vec3f() : Vector<float,3>(){}
    Vec3f(std::initializer_list<float> inil) : Vector<float,3>(inil){}
};
class Vec4f :public Vector<float,4>{
public:
    Vec4f() : Vector<float,4>(){}
    Vec4f(std::initializer_list<float> inil) : Vector<float,4>(inil){}
};

#include "Vector.hpp"

#endif
