#include "csgTree.h"

csgTree csgTree::addPrimitive(csgNode* node){
    feuilles.insert(std::pair<int,csgNode*>(nbNode++,node));
    return *this;
}

csgTree csgTree::joinPrimitive(int n1,int n2,csg_typeoperation op){
    csgOperation* node_op=new csgOperation(*(feuilles.find(n1)->second),*(feuilles.find(n2)->second),op);
    std::cout << "node create" << std::endl;
    feuilles.find(n1)->second->set_parent(node_op);
    feuilles.find(n2)->second->set_parent(node_op);
    /*feuilles.erase(n1);
    feuilles.erase(n2);
    updateMap();*/
    feuilles.insert(std::pair<int,csgNode*>(nbNode++,node_op));

    return *this;
}

bool csgTree::intersect(float x,float y)const{
    for(std::map<int,csgNode*>::const_iterator it=feuilles.begin();it!=feuilles.end();++it){
        if(it->second->get_parent() ==NULL && it->second->intersect(x,y))
            return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &out,const Image2Grey& i){
    for(uint y = 0;y<i.height();y++){
        for(uint x = 0;x<i.width();x++){
            out << (int)i(x,y) << " ";
        }
        out << std::endl;
    }
    return out;
}

Image2Grey csgTree::drawInImage(Image2Grey& im)const{
    for(unsigned int i=0;i<im.width();i++){
        for(unsigned int j=0;j<im.height();j++){
            im(i,j) = (this->intersect(i,j))?255:0;
        }
    }
    return im;
}

void csgTree::updateMap(){
    std::map<int,csgNode*> new_map;
    int nb=0;

    for(std::map<int,csgNode*>::const_iterator it=feuilles.begin();it!=feuilles.end();++it){
        new_map.insert(std::pair<int,csgNode*>(nb++,it->second));
    }

    feuilles = new_map;
    nbNode = nb;
}
