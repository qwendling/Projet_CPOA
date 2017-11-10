#include <iostream>
#include "Vector.h"
#include <assert.h>

int main()
{
    Vector<float,3> v1{1.f,2.f,3.f};
    Vector<float,3> v2{10.f,20.f,30.f};
    Vector<float,3> v_test_add = v1 + v2;
    Vector<float,3> v_test_sub = v_test_add-v1;
    Vector<float,2> v_test_const(v1);

    std::cout << v_test_const << std::endl;

    //Debut test operations entre vecteurs

    //on test si l'addition marche
    assert(v_test_add[0] == 11.f && v_test_add[1] == 22.f && v_test_add[2] == 33.f);
    std::cout << v_test_add << std::endl;
    //on test si la soustraction marche
    assert(v2==v_test_sub);
    std::cout << v_test_sub << std::endl;

    //on test si += marche
    v1+=v2;
    //Ici on a toujours v_test_add = v1+v2
    assert(v1==v_test_add);
    std::cout << v1 <<std::endl;

    //on test si -= marche
    v1-=v_test_sub;
    //Ici on a toujours v_test_sub = v2 et v1 = v1+v2
    assert(v1[0] == 1.f && v1[1] == 2.f && v1[2] == 3.f);
    std::cout << v1 <<std::endl;


    //Fin des test operations entre vecteurs

    //Debut test scalaire

    //Actuellement v1 = {1,2,3}
    Vector<float,3> v_test_mult = v1 * 2;

    assert(v_test_mult[0] == 2.f && v_test_mult[1] == 4.f && v_test_mult[2] == 6.f);
    std::cout << v_test_mult <<std::endl;

    Vector<float,3> v_test_mult2 = 2 * v1;
    assert(v_test_mult2==v_test_mult);
    std::cout << v_test_mult2 << std::endl;

    Vector<int,3> v_int1{1,2,3};
    Vector<int,3> v_int2{2,4,6};
    Vector<int,3> v_test_div = v_int2 / 2;
    assert(v_test_div == v_int1);
    std::cout << v_test_div << std::endl;

    //Fin test scalaire

    //Test produit scalaire
    int test_scalaire = v_int1 * v_int2;
    assert(test_scalaire == 2+8+18);
    std::cout << test_scalaire << std::endl;

    //Test produit vectoriel
    Vector<int,3> v_int3{4,2,7};
    Vector<int,3> v_test_vect = vect(v_int1,v_int3);
    assert((v_test_vect * v_int1) == 0);
    std::cout << v_test_vect << std::endl;

    Vec2f test2f{1.5f,5.f};
    std::cout << test2f << std::endl;

	return 0;
}


