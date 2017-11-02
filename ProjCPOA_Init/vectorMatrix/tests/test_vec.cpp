#include <iostream>
#include "Vector.h"
#include <assert.h>

int main()
{
    Vector<float,3> v1{1.f,2.f,3.f};
    Vector<float,3> v2{10.f,20.f,30.f};
    Vector<float,3> v3 = v1 + v2;
    Vector<float,3> v4 = v3-v1;

    assert(v3[0] == 11.f && v3[1] == 22.f && v3[2] == 33.f);
    std::cout << v3 << std::endl;
    assert(v2==v4);
    std::cout << v4 << std::endl;

	return 0;
}


