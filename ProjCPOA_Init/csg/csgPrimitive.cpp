#include "csgPrimitive.h"


bool csgPrimitive::intersectBBox(float x,float y) const{
    return box.isInBox(Vec2f({x,y}));
}

void csgPrimitive::applyTransfo(const Matrix33d& m){
    box = BoundingBox(-0.5f,0.5f,0.5f,-0.5f);
    std::cout << m << std::endl;
    global_transform = m*inProgress.invert()*global_transform;
    std::cout << "premier invert" << std::endl;
    inProgress = m;
    inverse = global_transform.invert();
    std::cout << "deuxieme invert" << std::endl;
    box.applyTransfo(global_transform);
}
