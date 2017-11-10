#include "Matrix33d.h"
#include <math.h>


std::ostream &operator<<(std::ostream &out,const Matrix33d& m){
    out << '{';
    out << m[0];
    for(int i=1;i<3;i++){
        out << ",\n " << m[i];
    }
    out << '}';
    return out;
}


double Matrix33d::operator()(const int x,const int y) const {
    return (data[y])[x];
}

double& Matrix33d::operator()(const int x,const int y){
    return (data[y])[x];
}

double Matrix33d::determinant()const{
    double tmp1 = (*this)(0,0)*((*this)(1,1)*(*this)(2,2)-(*this)(2,1)*(*this)(1,2));
    double tmp2 = (*this)(1,0)*((*this)(0,1)*(*this)(2,2)-(*this)(2,1)*(*this)(0,2));
    double tmp3 = (*this)(2,0)*((*this)(0,1)*(*this)(1,2)-(*this)(1,1)*(*this)(0,2));
    return tmp1-tmp2+tmp3;
}

Matrix33d Matrix33d::invert() const{
    double det = this->determinant();
    assert(det > 0.0000001 || det < -0.0000001);
    Matrix33d inverse;
    inverse(0,0) = ((*this)(1,1)*(*this)(2,2)-(*this)(2,1)*(*this)(1,2))/det;
    inverse(1,0) = -((*this)(1,0)*(*this)(2,2)-(*this)(1,2)*(*this)(2,0))/det;
    inverse(2,0) = ((*this)(1,0)*(*this)(2,1)-(*this)(1,1)*(*this)(2,0))/det;

    inverse(0,1) = -((*this)(0,1)*(*this)(2,2)-(*this)(2,1)*(*this)(0,2))/det;
    inverse(1,1) = ((*this)(0,0)*(*this)(2,2)-(*this)(0,2)*(*this)(2,0))/det;
    inverse(2,1) = -((*this)(0,0)*(*this)(2,1)-(*this)(0,1)*(*this)(2,0))/det;

    inverse(0,2) = ((*this)(0,1)*(*this)(1,2)-(*this)(0,2)*(*this)(1,1))/det;
    inverse(1,2) = -((*this)(0,0)*(*this)(1,2)-(*this)(0,2)*(*this)(1,0))/det;
    inverse(2,2) = ((*this)(0,0)*(*this)(1,1)-(*this)(1,0)*(*this)(0,1))/det;

    return inverse;
}

Matrix33d Matrix33d::Identity(){
    Matrix33d id;
    id(0,0) = 1;
    id(1,1) = 1;
    id(2,2) = 1;

    return id;
}

Matrix33d Matrix33d::scale(const double kx,const double ky){
    Matrix33d s = Identity();
    s(0,0) = kx;
    s(1,1) = ky;

    return s;
}

Matrix33d Matrix33d::translate(const double dx,const double dy){
    Matrix33d t = Identity();

    t(2,0) = dx;
    t(2,1) = dy;

    return t;
}

Matrix33d Matrix33d::rotate(const double alpha){
    Matrix33d r = Identity();

    r(0,0) = cos(alpha);
    r(1,0) = -sin(alpha);
    r(0,1) = sin(alpha);
    r(1,1) = cos(alpha);

    return r;
}

Matrix33d Matrix33d::operator*(const Matrix33d& m)const{
    int i,j,k;
    Matrix33d result;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                result(i,j)+=(*this)(k,j)*m(i,k);
            }
        }
    }
    return result;
}

void Matrix33d::applyRotation(const double alpha){
    *this = rotate(alpha)*(*this);
}

void Matrix33d::applyScale(const double kx,const double ky){
    *this = scale(kx,ky)*(*this);
}

void Matrix33d::applyTranslate(const double dx,const double dy){
    *this = translate(dx,dy)*(*this);
}

void Matrix33d::setRotation(const double alpha){
    *this = rotate(alpha);
}

void Matrix33d::setScale(const double kx,const double ky){
    *this = scale(kx,ky);
}

void Matrix33d::setTranslate(const double dx,const double dy){
    *this = translate(dx,dy);
}

Vec3f Matrix33d::operator*(const Vec3f& v)const{
    Vec3f result;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            result[i] += (*this)(j,i)*v[j];
        }
    }

    return result;
}

Vec2f Matrix33d::apply(Vec2f& v)const{
    v = Vec2f((*this)*Vec3f(v));
    return v;
}


