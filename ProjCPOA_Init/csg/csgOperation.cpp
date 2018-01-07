#include "csgOperation.h"


bool csgOperation::intersectBBox(float x, float y)const{
    switch(type_op){
        case csgUnion:
            return (fils_droit.get_BoundingBox()+fils_gauche.get_BoundingBox()).isInBox(Vec2f({x,y}));
            break;
        case csgDiff:
            return (fils_droit.get_BoundingBox()-fils_gauche.get_BoundingBox()).isInBox(Vec2f({x,y}));
            break;
        case csgInter:
            return (fils_droit.get_BoundingBox()^fils_gauche.get_BoundingBox()).isInBox(Vec2f({x,y}));
            break;
    }
    return false;
}


bool csgOperation::intersect(float x, float y) const{
    switch(type_op){
        case csgUnion:
            return fils_droit.intersect(x,y) || fils_gauche.intersect(x,y);
            break;
        case csgDiff:
            return fils_droit.intersect(x,y) && !fils_gauche.intersect(x,y);
            break;
        case csgInter:
            return fils_droit.intersect(x,y) && fils_gauche.intersect(x,y);
            break;
    }
    return false;
}

void csgOperation::applyTransfo(const Matrix33d& m){
    Matrix33d tmp_m = m;
    if(get_parent() != NULL){
        tmp_m = get_parent()->global_transform*tmp_m;
    }
    global_transform = global_transform*inProgress.invert()*tmp_m;
    inProgress = tmp_m;

    fils_droit.applyTransfo(inverse*fils_droit.inProgress);
    fils_gauche.applyTransfo(inverse*fils_gauche.inProgress);

    inverse = global_transform.invert();

    std::cout << "transform operation " << std::endl;
}
