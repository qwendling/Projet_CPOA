#ifndef CSGOPERATION_H
#define CSGOPERATION_H

#include "csgNode.h"

typedef enum{
    csgUnion,
    csgInter,
    csgDiff,
} csg_typeoperation;

class csgOperation : public csgNode{
public:
    csgNode& fils_droit;
    csgNode& fils_gauche;
    csg_typeoperation type_op;
    csgOperation() = delete;
    csgOperation(const csgOperation& cp):csgNode(cp),fils_droit(cp.fils_droit),fils_gauche(cp.fils_gauche){}
    csgOperation(csgNode& f_droit,csgNode& f_gauche,csg_typeoperation op):csgNode(),fils_droit(f_droit),fils_gauche(f_gauche),type_op(op){}
    bool intersect(float, float) const;
    bool intersectBBox(float, float)const;
};



#endif
