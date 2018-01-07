#include "csgDisk.h"

bool csgDisk::intersect(float x, float y) const{
    if(!this->intersectBBox(x,y)){
        return false;
    }
    Vec3f p_local = inverse*Vec3f({x,y,1});
    float distance_centre = p_local[0]*p_local[0]+p_local[1]*p_local[1];
    return distance_centre<=(0.5*0.5);
}
