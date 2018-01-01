#include "csgPrimitive.h"


bool csgPrimitive::intersectBBox(float x,float y) const{
    return box.isInBox(Vec2f({x,y}));
}
