#include "csgPrimitive.h"


bool csgPrimitive::intersectBBox(float x,float y) const{
    return box.isInBox(Vec2f({x,y}));
}

void csgPrimitive::applyTransfo(const Matrix33d& m){
    box = BoundingBox(-0.5f,0.5f,0.5f,-0.5f);
    global_transform = global_transform*inProgress.invert()*m;
    inProgress = m;
    inverse = global_transform.invert();
    box.applyTransfo(global_transform);
}
