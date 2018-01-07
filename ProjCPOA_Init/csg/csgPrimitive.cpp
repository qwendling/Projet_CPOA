#include "csgPrimitive.h"


bool csgPrimitive::intersectBBox(float x,float y) const{
    return box.isInBox(Vec2f({x,y}));
}

void csgPrimitive::applyTransfo(const Matrix33d& m){
    Matrix33d tmp_m = m;
    if(get_parent() != NULL){
        tmp_m = get_parent()->global_transform*tmp_m;
    }
    box = BoundingBox(-0.5f,0.5f,0.5f,-0.5f);
    global_transform = global_transform*inProgress.invert()*tmp_m;
    inProgress = tmp_m;
    inverse = global_transform.invert();
    box.applyTransfo(global_transform);
    std::cout << "transform prim " << std::endl;
}
