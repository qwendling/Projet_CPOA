#include "csgNode.h"
#include <iostream>


int main(){
    csgNode test;
    test.set_label("Nonoeud");
    csgNode test2(test);
    std::cout << "hello world" << std::endl;
    return 0;
}
