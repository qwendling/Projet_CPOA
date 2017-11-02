#include <iostream>
#include "Vector.h"
#include <assert.h>

int main()
{
    Vector<float,3> v1{1.f,2.f,3.f};
    Vector<float,3> v2{10.f,20.f,30.f};
    Vector<float,3> v3 = v1 + v2;
    Vector<float,3> v4 = v3-v1;

    //on test si l'addition marche
    assert(v3[0] == 11.f && v3[1] == 22.f && v3[2] == 33.f);
    std::cout << v3 << std::endl;
    //on test si la soustraction marche
    assert(v2==v4);
    std::cout << v4 << std::endl;

    //on test si += marche
    v1+=v2;
    //Ici on a toujours v3 = v1+v2
    assert(v1==v3);
    std::cout << v1 <<std::endl;

    //on test si -= marche
    v1-=v4;
    //Ici on a toujours v4 = v2 et v1 = v1+v2
    assert(v1[0] == 1.f && v1[1] == 2.f && v1[2] == 3.f);
    std::cout << v1 <<std::endl;

	return 0;
}


