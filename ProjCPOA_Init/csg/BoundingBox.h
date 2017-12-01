#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "Vector.h"

class BoundingBox{
public:
    Vec2f p1;
    Vec2f p2;
    BoundingBox() = delete;
    BoundingBox(float p1x,float p1y,float p2x,float p2y) : p1{p1x,p1y},p2{p2x,p2y}{}
    BoundingBox(Vec2f p1,Vec2f p2) : BoundingBox(p1[0],p1[1],p2[0],p2[1]){}
    Vec2f getp1();
    Vec2f getp2();

    BoundingBox operator+(BoundingBox&);
    BoundingBox operator-(BoundingBox&);
    BoundingBox Inter(BoundingBox&);
};



#endif
