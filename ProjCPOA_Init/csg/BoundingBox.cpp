#include "BoundingBox.h"
#include "vector"


Vec2f BoundingBox::getp1()const{
    return this->p1;
}
Vec2f BoundingBox::getp2()const{
    return this->p2;
}

BoundingBox BoundingBox::operator+(const BoundingBox& bb)const{
    return BoundingBox(std::max(bb.getp1()[0],this->getp1()[0]),\
            std::max(bb.getp1()[1],this->getp1()[1]),\
            std::min(bb.getp2()[0],this->getp2()[0]),\
            std::min(bb.getp2()[1],this->getp2()[1]));
}
BoundingBox BoundingBox::operator-(const BoundingBox& bb)const{
    return *this;
}
BoundingBox BoundingBox::operator^(const BoundingBox& bb)const{
    float yMax,yMin,xMax,xMin;
    yMax = std::min(this->getp1()[1],bb.getp1()[1]);
    yMin = std::max(this->getp2()[1],bb.getp2()[1]);
    xMax = std::min(this->getp2()[0],bb.getp2()[0]);
    xMin = std::max(this->getp1()[0],bb.getp1()[0]);
    return BoundingBox(xMin,yMax,xMax,yMin);
}

bool BoundingBox::isEmpty()const{
    return this->getp1()[0]>this->getp2()[0] || this->getp1()[1]<this->getp2()[1];
}


Vec2f BoundingBox::getCenter()const{
    float y = (this->getp1()[1]+this->getp2()[1])/2;
    float x = (this->getp1()[1]+this->getp2()[1])/2;
    return Vec2f({x,y});
}

bool BoundingBox::isInBox(const Vec2f& p)const{
    return this->getp1()[1]>p[1] && this->getp1()[0]<p[0] &&this->getp2()[0]>p[0] && this->getp2()[1]<p[1];
}

void BoundingBox::addPoint(const Vec2f& p){
    if(p[0]<this->getp1()[0]){
        this->getp1()[0] = p[0];
    }
    if(p[0]>this->getp2()[0]){
        this->getp2()[0] = p[0];
    }
    if(p[1]>this->getp1()[1]){
        this->getp1()[1] = p[1];
    }
    if(p[1]<this->getp2()[1]){
        this->getp2()[1] = p[1];
    }
}

void BoundingBox::applyTransfo(const Matrix33d& m){
    Vec2f p1_trans = m*p1;
    Vec2f p2_trans = m*p2;
    Vec2f p3_trans = m*p3;
    Vec2f p4_trans = m*p4;

}
