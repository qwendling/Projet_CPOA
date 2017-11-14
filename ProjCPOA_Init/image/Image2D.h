#ifndef IMAGE2D_H
#define IMAGE2D_H
#include <utility>
#include <iostream>
#include "assert.h"


template<typename T>
class Image2D
{
protected:
    T* pixels_;
    uint w_;
    uint h_;

public:
    Image2D(uint w, uint h):w_(w),h_(h)
    {
        pixels_ = new T[w*h];
    }

    Image2D(const Image2D& im) {
        w_ = im.width();
        h_ = im.height();
        pixels_ = new T[im.width()*im.height()];
        for(uint i=0;i<im.width();i++){
            for(uint j=0;j<im.height();j++){
                (*this)(i,j) = im(i,j);
            }
        }
    }

    Image2D() = delete;

    ~Image2D()
    {
        delete[] pixels_;
    }

    uint width() const {return w_;}
    uint height() const {return h_;}

    T* data_pix() { return pixels_;}

    T& operator ()(int i,int j) { return pixels_[i+j*w_];}

    const T& operator ()(int i,int j) const { return pixels_[i+j*w_];}

    void swap_pixels(Image2D<T>& im)
    {
        assert(im.width()==this->width() && im.height()==this->height());
        std::swap(im.pixels_,this->pixels_);
    }

    Image2D cropping(uint x,uint y,uint w,uint h){
        if(w+x > this->width()){
            w = this->width() - x;
        }
        if(h+y > this->height()){
            h = this->height()-y;
        }
        Image2D<T> result(w,h);

        int x_tmp=x;
        int y_tmp;
        for(uint i=0;i<w;i++,x_tmp++){
            y_tmp=y;
            for(uint j=0;j<h;j++,y_tmp++){
                result(i,j) = (*this)(x_tmp,y_tmp);
            }
        }


        return result;
    }

    void convol3x3(const double* m)
    {
        Image2D<T> im(w_,h_);

        for(int j=1;j<h_-1;j++)
            for(int i=1;i<w_-1;i++)
            {
                double v = 0;
                const double* p = m;
                for(int l=-1;l<2;l++)
                    for(int k=-1;k<2;k++)
                        v += (*this)(i+k,j+l)*(*p++);
                im(i,j) = T(v);
            }

        // copie du bord
        for(int j=0;j<h_;j++)
        {
            im(0,j) = (*this)(0,j);
            im(w_-1,j) = (*this)(w_-1,j);
        }

        for(int i=0;i<w_;i++)
        {
            im(i,0) = (*this)(i,0);
            im(i,h_-1) = (*this)(i,h_-1);
        }

        swap_pixels(im);
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &out,const Image2D<T>& i){
    for(uint y = 0;y<i.height();y++){
        for(uint x = 0;x<i.width();x++){
            out << i(x,y) << " ";
        }
        out << std::endl;
    }
    return out;
}

#endif
