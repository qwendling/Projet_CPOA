#include "BoundingBox.h"


Vec2f BoundingBox::getp1(){
    return this->p1;
}
Vec2f BoundingBox::getp2(){
    return this->p2;
}

BoundingBox BoundingBox::operator+(BoundingBox& bb){
    return BoundingBox(std::max(bb.getp1()[0],this->getp1()[0]),\
            std::max(bb.getp1()[1],this->getp1()[1]),\
            std::min(bb.getp2()[0],this->getp2()[0]),\
            std::min(bb.getp2()[1],this->getp2()[1]));
}
BoundingBox BoundingBox::operator-(BoundingBox& bb){
    return *this;
}
BoundingBox BoundingBox::Inter(BoundingBox& bb){
    return *this;
}
