#include "csgTree.h"

csgTree csgTree::addPrimitive(csgNode& node){
    feuilles.insert(&node);
    return *this;
}

csgTree csgTree::joinPrimitive(csgNode& n1,csgNode& n2,csg_typeoperation op){
    csgOperation* node_op=new csgOperation(n1,n2,op);
    feuilles.erase(&n1);
    feuilles.erase(&n2);
    feuilles.insert(node_op);
    return *this;
}

bool csgTree::intersect(float x,float y)const{
    for(std::set<csgNode*>::iterator it=feuilles.begin();it!=feuilles.end();++it){
        if((*it)->intersect(x,y))
            return true;
    }
    return false;
}

Image2Grey csgTree::drawInImage(Image2Grey& im)const{
    for(unsigned int i=0;i<im.width();i++){
        for(unsigned int j=0;j<im.height();j++){
            im(i,j) = (this->intersect(i,j))?255:0;
        }
    }
    return im;
}
