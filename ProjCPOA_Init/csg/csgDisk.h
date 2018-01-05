#ifndef CSGDISK_H
#define CSGDISK_H
#include "csgPrimitive.h"

class csgDisk : public csgPrimitive{
public:
    csgDisk():csgPrimitive(){}
    csgDisk(const csgDisk& cp) : csgPrimitive(cp){}
    bool intersect(float, float) const;
};




#endif
