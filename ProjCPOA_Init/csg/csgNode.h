#ifndef CSGNODE_H
#define CSGNODE_H
#include <iostream>
#include "BoundingBox.h"

class csgNode{
protected:
    std::string label;
    int id;
    csgNode* parent;
    BoundingBox box;
public:
    static int nbNode;
    csgNode();
    csgNode(const csgNode&);

    ~csgNode();

    Matrix33d inProgress;
    Matrix33d global_transform;
    Matrix33d inverse;

    void set_label(std::string);
    void set_parent(csgNode*);

    std::string get_label() const;
    int get_id() const;
    csgNode* get_parent() const;
    BoundingBox get_BoundingBox()const{return box;}

    virtual bool intersect(float,float)const=0;
    virtual bool intersectBBox(float,float)const=0;
    virtual void applyTransfo(const Matrix33d&)=0;

    int windows_translateX;
    int windows_translateY;
    int windows_scale;
    int windows_rotate;
};



#endif
