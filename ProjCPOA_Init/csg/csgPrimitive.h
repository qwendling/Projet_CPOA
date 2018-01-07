#ifndef CSGPRIMITIVE_H
#define CSGPRIMITIVE_H
#include "csgNode.h"
#include "Matrix33d.h"

class csgPrimitive : public csgNode{
public:
    Matrix33d inProgress;
    Matrix33d global_transform;
    Matrix33d inverse;
    csgPrimitive() : csgNode(){
        inProgress = Matrix33d::Identity();
        global_transform = Matrix33d::Identity();
        inverse = Matrix33d::Identity();
        box = BoundingBox(-0.5f,0.5f,0.5f,-0.5f);
    }

    void applyTransfo(const Matrix33d&);

    csgPrimitive(const csgPrimitive& cp) : csgNode(cp),
            inProgress(cp.inProgress),
            global_transform(cp.global_transform),
            inverse(cp.inverse){}
    bool intersectBBox(float x, float y)const;
};


#endif
