#ifndef CSGNODE_H
#define CSGNODE_H
#include <iostream>

class csgNode{
protected:
    std::string label;
    int id;
    csgNode* parent;
public:
    static int nbNode;
    csgNode();
    csgNode(const csgNode&);

    ~csgNode();

    void set_label(std::string);
    void set_parent(csgNode*);

    std::string get_label() const;
    int get_id() const;
    csgNode* get_parent() const;


};



#endif
