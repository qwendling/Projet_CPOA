#ifndef MATRIX33D_H
#define MATRIX33D_H
#include "Array.h"
#include "Vector.h"

class Matrix33d : public Array<Array<double,3>,3>
{
public:
    Matrix33d() : Array<Array<double,3>,3>() {}
    inline Matrix33d(std::initializer_list<std::initializer_list<double>> inil){
        assert(inil.size() <= 3);
        int j=0;
        for(std::initializer_list<double> x: inil)
            data[j++]=Array<double,3>(x);
    }
    friend std::ostream &operator<<(std::ostream &out,const Matrix33d& m);
    double operator()(const int x,const int y) const;
    double& operator()(const int x,const int y);
    double determinant()const;
    Matrix33d invert() const;

    static Matrix33d Identity();
    static Matrix33d scale(const double kx,const double ky);
    static Matrix33d translate(const double dx,const double dy);
    static Matrix33d rotate(const double alpha);

    Matrix33d operator*(const Matrix33d&)const;
    void applyRotation(const double alpha);
    void applyScale(const double kx,const double ky);
    void applyTranslate(const double dx,const double dy);

    void setRotation(const double alpha);
    void setScale(const double kx,const double ky);
    void setTranslate(const double dx,const double dy);

    Vec3f apply(Vec3f&)const;
    Vec2f apply(Vec2f&)const;
};

#endif
