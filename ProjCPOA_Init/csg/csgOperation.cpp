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
