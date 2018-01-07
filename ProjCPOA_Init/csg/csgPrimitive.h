#ifndef CSGPRIMITIVE_H
#define CSGPRIMITIVE_H
#include "csgNode.h"
#include "Matrix33d.h"

class csgPrimitive : public csgNode{
public:
    csgPrimitive() : csgNode(){
        box = BoundingBox(-0.5f,0.5f,0.5f,-0.5f);
    }

    void applyTransfo(const Matrix33d&);

    csgPrimitive(const csgPrimitive& cp) : csgNode(cp){}
    bool intersectBBox(float x, float y)const;
};


#endif
