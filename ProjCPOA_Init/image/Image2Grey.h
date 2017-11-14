#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H
#include "Image2D.h"

class Image2Grey : public Image2D<unsigned char>{
public:
    Image2Grey(uint w, uint h) : Image2D(w,h){}

    Image2Grey(const Image2Grey& im) : Image2D(im) {}

    static Image2Grey chargerPGM(const std::string& path);
    void sauvegarderPGM(const std::string& path);
    friend std::ostream &operator<<(std::ostream &out,const Image2Grey& i);
};


#endif
