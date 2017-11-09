#include "Matrix33d.h"


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

Matrix33d Matrix33d::scale(double kx,double ky){
    Matrix33d s = Identity();
    s(0,0) = kx;
    s(1,1) = ky;

    return s;
}

Matrix33d Matrix33d::translate(double dx,double dy){
    Matrix33d t = Identity();

    s(2,0) = dx;
    s(2,1) = dy;

    return t;
}
