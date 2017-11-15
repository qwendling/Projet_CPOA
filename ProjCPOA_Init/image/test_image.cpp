#include "Image2D.h"
#include "Image2Grey.h"
#include "Image2RGB.h"
#include "GradientSobel.h"
#include <unistd.h>


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

    Image2D<int> im2 = test_image.cropping(2,2,10,10);

    std::cout << im2 << std::endl;

    std::string path = get_current_dir_name();
    path += "/../../ProjCPOA_Init/image";

    Image2Grey test_grey = Image2Grey::chargerPGM(path+"/test.pgm");
    std::cout << test_grey << std::endl;

    test_grey.sauvegarderPGM(path+"/test2.pgm");

    std::cout << "sous echantllonnage\n" << test_grey.sousEch() << std::endl;

    test_grey.sousEch().sauvegarderPGM(path+"/test3.pgm");

    std::cout << test_grey.lissage(5) << std::endl;
    test_grey.lissage(5).sauvegarderPGM(path+"/test4.pgm");

    GradientSobel::Sobel(test_grey);

    Image2RGB test_rgb = Image2RGB::chargerPPM(path+"/test.ppm");

    test_rgb.cropping(50,50,80,42);

    test_rgb.sauvegarderPPM(path+"/test2.ppm");

    return 0;
}
