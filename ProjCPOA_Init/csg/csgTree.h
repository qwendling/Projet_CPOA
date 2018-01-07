#ifndef CSGTREE_H
#define CSGTREE_H

#include "csgNode.h"
#include "csgOperation.h"
#include "Image2Grey.h"
#include <set>
#include <map>



class csgTree{
public:
    int nbNode;
    std::map<int,csgNode*> feuilles;
    csgTree():nbNode(0){}
    csgTree addPrimitive(csgNode*);
    csgTree joinPrimitive(int,int,csg_typeoperation);
    bool intersect(float,float)const;
    Image2Grey drawInImage(Image2Grey&)const;
};


#endif
