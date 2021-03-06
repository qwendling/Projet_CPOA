#include <iostream>
#include "Array.h"
#include <assert.h>

int main()
{
    Array<float,5> a0;
    std::cout << a0 << std::endl;
    Array<float,5> a1{1,2,3,4,5};

    Array<float,2> test_const(a1);
    assert(a1[0] == test_const[0] && a1[1] == test_const[1]);

    std::cout << test_const << std::endl;

    assert(a1[0] == 1);
    std::cout << "test acces ok" <<std::endl;

    std::cout << "a1 : " << a1 << std::endl;

    Array<float,5> a2{10,15,46,71,3};
    std::cout << "a2 : " << a2 << std::endl;


    Array<float,5> a3 = a1;
    a1.swap(a2);

    std::cout << "swap" << std::endl;
    std::cout << "a1 : " << a1 <<std::endl;
    std::cout << "a2 : " << a2 <<std::endl;
    std::cout << "a3 : " << a3 <<std::endl;

    assert(a1==a1);

    assert(a1!=a2);
    std::cout << "test egalite ok" << std::endl;
    assert(a2==a3);
    std::cout << "test copie ok" << std::endl;

    return 0;
}
