#include "csgNode.h"
#include <iostream>

int csgNode::nbNode=0;
std::ostream &operator<<(std::ostream &out,const csgNode& n){
    out << "name : " << n.get_label() << "identifiant : " << n.get_id();
    return out;
}


csgNode::csgNode(){
    id = nbNode++;
    parent==NULL;
    std::cout << *(this) << " construit !" << std::endl;
}

csgNode::csgNode(const csgNode& n){
    this->set_label(n.get_label());
    this->set_parent(n.get_parent());
    this->id=nbNode++;
    box = n.get_BoundingBox();
    std::cout << *(this) << " construit !" << std::endl;
}

csgNode::~csgNode(){
    std::cout << *(this) << " detruit !" << std::endl;
}


void csgNode::set_label(std::string label){
    this->label = label;
}

void csgNode::set_parent(csgNode* n){
    this->parent = n;
}

std::string csgNode::get_label() const{
    return this->label;
}
int csgNode::get_id() const{
    return this->id;
}
csgNode* csgNode::get_parent() const{
    return this->parent;
}
