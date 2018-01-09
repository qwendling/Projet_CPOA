#ifndef GRADIENTSOBEL_H
#define GRADIENTSOBEL_H
#include "Image2D.h"
#include "Image2Grey.h"
#include "Vector.h"

class GradientSobel{
public:
    GradientSobel() = delete;
    GradientSobel(const GradientSobel& gs) = delete;
    static const int Sobel5x[25];

    static const int Sobel5y[25];

    static Image2D<Vec2f>* Sobel(const Image2Grey&);
};



#endif
