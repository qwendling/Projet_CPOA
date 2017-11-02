template<typename T>
class Image
{
protected:
    T* pixels_;
    int w_;
    int h_;

public:
    Image(int w, int h):w_(w),h_(h)
    {
        pixels_ = new T[w*h];
    }

    Image(const Image& im) = delete;

    Image() = delete;

    ~Image()
    {
        delete[] pixels_;
    }

    int width() const {return w_;}
    int height() const {return h_;}

    T* data_pix() { return pixels_;}

    T& operator ()(int i,int j) { return pixels_[i+j*w_];}

    const T& operator ()(int i,int j) const { return pixels_[i+j*w_];}

    void swap_pixels(Image<T>& im)
    {
        assert(im.width()==this->width() && im.height()==this->height());
        std::swap(im.pixels_,this->pixels_);
    }

    void convol3x3(const double* m)
    {
        Image<T> im(w_,h_);

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


/// version pour les types (P)Array
/// le type P doit fournir [] -> type numeric, et size()
template <typename P>
auto convol3x3(Image<P>& image, const double* m) -> typename std::enable_if<!std::is_arithmetic<P>::value,void>::type
{

    int w = image.width();
    int h = image.height();

    Image<P> im(image.width(),image.height());

    for(int j=1;j<h-1;j++)
        for(int i=1;i<w-1;i++)
        {
            P v;
            for(int iv=0; iv<v.size(); ++iv)
                v[i]=0;
            const double* p = m;
            for(int l=-1;l<2;l++)
                for(int k=-1;k<2;k++)
                {
                    auto& u = image(i+k,j+l);
                    for(int iv=0; iv<v.size(); ++iv)
                        v[i] += u[i] * (*p);
                    p++;
                }
            im(i,j) = v;
        }

    for(int j=0;j<h;j++)
    {
        im(0,j) = image(0,j);
        im(w-1,j) = image(w-1,j);
    }

    for(int i=0;i<w;i++)
    {
        im(i,0) = image(i,0);
        im(i,h-1) = image(i,h-1);
    }

    image.swap_pixels(im);
}

/// version pour les types (P) numériques
template <typename P>
auto convol3x3(Image<P>& image, const double* m) -> typename std::enable_if<std::is_arithmetic<P>::value,void>::type
{
    int w = image.width();
    int h = image.height();

    Image<P> im(image.width(),image.height());

    for(int j=1;j<h-1;j++)
        for(int i=1;i<w-1;i++)
        {
            P v(0);
            const double* p = m;
            for(int l=-1;l<2;l++)
                for(int k=-1;k<2;k++)
                    v += image(i+k,j+l)*(*p++);
            im(i,j) = v;
        }

    for(int j=0;j<h;j++)
    {
        im(0,j) = image(0,j);
        im(w-1,j) = image(w-1,j);
    }

    for(int i=0;i<w;i++)
    {
        im(i,0) = image(i,0);
        im(i,h-1) = image(i,h-1);
    }

    image.swap_pixels(im);
}
