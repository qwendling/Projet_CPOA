#include "Image2D.h"


int main(){

    Image2D<int> test_image(4,4);
    test_image(0,0) = 0;
    test_image(1,0) = 1;
    test_image(2,0) = 2;
    test_image(3,0) = 3;

    test_image(0,1) = 4;
    test_image(1,1) = 5;
    test_image(2,1) = 6;
    test_image(3,1) = 7;

    test_image(0,2) = 8;
    test_image(1,2) = 9;
    test_image(2,2) = 10;
    test_image(3,2) = 11;

    test_image(0,3) = 12;
    test_image(1,3) = 13;
    test_image(2,3) = 14;
    test_image(3,3) = 15;

    std::cout << test_image << std::endl;

    test_image.cropping(2,2,10,10);

    std::cout << test_image << std::endl;

    return 0;
}
