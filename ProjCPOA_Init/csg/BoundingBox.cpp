#include "BoundingBox.h"
#include <vector>
#include <algorithm>


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


    Vec2f p1_trans = m*Vec3f({p1[0],p1[1],1});
    Vec2f p2_trans = m*Vec3f({p2[0],p2[1],1});
    Vec2f p3_trans = m*Vec3f({p1[0],p2[1],1});
    Vec2f p4_trans = m*Vec3f({p2[0],p1[1],1});


    std::vector<Vec2f> vec_transfo;
    vec_transfo.push_back(p1_trans);
    vec_transfo.push_back(p2_trans);
    vec_transfo.push_back(p3_trans);
    vec_transfo.push_back(p4_trans);

    auto minMax_x = std::minmax_element(vec_transfo.begin(), vec_transfo.end(),[](const Vec2f& v1, const Vec2f& v2) {
        return v1[0] < v2[0];
    });

    auto minMax_y = std::minmax_element(vec_transfo.begin(), vec_transfo.end(),[](const Vec2f& v1, const Vec2f& v2) {
        return v1[1] < v2[1];
    });

    this->p1 = Vec2f({(*minMax_x.first)[0],(*minMax_y.second)[1]});
    this->p2 = Vec2f({(*minMax_x.second)[0],(*minMax_y.first)[1]});


}
