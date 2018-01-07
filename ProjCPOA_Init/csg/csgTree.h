#ifndef CSGTREE_H
#define CSGTREE_H

#include "csgNode.h"
#include "csgOperation.h"
#include "Image2Grey.h"
#include <set>


class csgTree{
public:
    std::set<csgNode*> feuilles;
    csgTree(){}
    csgTree addPrimitive(csgNode&);
    csgTree joinPrimitive(csgNode&,csgNode&,csg_typeoperation);
    bool intersect(float,float)const;
    Image2Grey drawInImage(Image2Grey&)const;
};


#endif
