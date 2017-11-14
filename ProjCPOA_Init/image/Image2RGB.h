#ifndef IMAGE2RGB_H
#define IMAGE2RGB_H
#include "Image2D.h"
#include "Vector.h"

class Image2RGB : public Image2D<Vec3uc>{
public:
    Image2RGB(uint w, uint h) : Image2D(w,h){}

    Image2RGB(const Image2RGB& im) : Image2D(im) {}
    static Image2RGB chargerPPM(const std::string& path);
    void sauvegarderPPM(const std::string& path)const;
};


#endif
