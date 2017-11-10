#include <iostream>
#include <assert.h>
#include "Matrix33d.h"

int main()
{
    Matrix33d m1{{1,2,3},{0,1,4},{5,6,0}};
    Matrix33d m2{{1,2,3},{4,5,6},{7,8,9}};

    std::cout << m2 << std::endl;
    std::cout << m2(1,0) << std::endl;
    assert(m2(1,0)==2);

    m2(2,1) = 12;
    std::cout << m2 << std::endl;
    assert(m2(2,1)==12);

    assert(m1.determinant() == 1);

    Matrix33d test_id{{1,0,0},{0,1,0},{0,0,1}};
    assert(test_id == Matrix33d::Identity());

    assert((m1 * Matrix33d::Identity()) == m1);


    std::cout << "m1 : \n" << m1 << "\nm1 inverse : \n" << m1.invert() << "\nm1 * inverse : \n" << m1*m1.invert() << std::endl;
    assert((m1 * m1.invert()) == Matrix33d::Identity());



    /*Matrix33d m1 = Matrix33d::identity();

	std::cout << "translate(3.5f,2.4f) "<<  std::endl;
	m1.translate(3.5f,2.4f);
	std::cout << m1 <<  std::endl;

	x = 0.0;
	y = 0.0;
	m1.applyTransformation(x,y);
	std::cout << "0,0 => "<< x << "," << y << std::endl;

	m1.rotate(0.4);
	Matrix33d m2 = m1.inverse();

    std::cout << m1 << std::endl<<"*"<< std::endl<<m2<< "=" << std::endl<< m1*m2 << std::endl;*/


	return 0;
}
