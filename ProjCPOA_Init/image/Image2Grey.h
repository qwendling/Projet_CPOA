#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H
#include "Image2D.h"
#include "Vector.h"

class Image2Grey : public Image2D<unsigned char>{
public:

    static const int Sobel5x[25]={1,2,0,-2,-1,
                                          4,8,0,-8,-4,
                                          6,12,0,-12,-6,
                                          4,8,0,-8,-4,
                                          1,2,0,-2,-1};

    static const int Sobel5y[25]={1, 4, 6, 4, 1,
                                          2, 8, 12, 8, 2,
                                          0, 0, 0, 0, 0,
                                          -2,-8,-12,-8,-2,
                                          -1,-4,-6,-4,-1};

    Image2Grey(uint w, uint h) : Image2D(w,h){}

    Image2Grey(const Image2Grey& im) : Image2D(im) {}

    static Image2Grey chargerPGM(const std::string& path);
    void sauvegarderPGM(const std::string& path)const;
    Image2Grey sousEch();
    friend std::ostream &operator<<(std::ostream &out,const Image2Grey& i);
    Image2Grey lissage(const uint n)const;
    void seuillage(const int seuil);

    static Image2D<Vec2f> GradientSobel(const Image2Grey&);
};


#endif
