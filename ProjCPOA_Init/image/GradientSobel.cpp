#include "GradientSobel.h"


const int GradientSobel::Sobel5x[25]={1,2,0,-2,-1,
                                      4,8,0,-8,-4,
                                      6,12,0,-12,-6,
                                      4,8,0,-8,-4,
                                      1,2,0,-2,-1};

const int GradientSobel::Sobel5y[25]={1, 4, 6, 4, 1,
                                      2, 8, 12, 8, 2,
                                      0, 0, 0, 0, 0,
                                      -2,-8,-12,-8,-2,
                                      -1,-4,-6,-4,-1};

Image2D<Vec2f> GradientSobel::Sobel(const Image2Grey& img){
    Image2D<Vec2f> result(img.width(),img.height());

    int n = 2,size=5;
    for(uint i=0;i<result.width();i++){
        for(uint j = 0;j<result.height();j++){
            int interX = 0,interY = 0;
            for(int x=-n;x<size-n;x++){
                for(int y=-n;y<size-n;y++){
                    if(i+x < 0 || j+y < 0 || i+x >= result.width() || j+y >= result.height())
                        continue;
                    interX += img(i+x,j+y)*Sobel5x[x+y*5];
                    interY += img(i+x,j+y)*Sobel5y[x+y*5];
                }
            }
            result(i,j)[0] = interX;
            result(i,j)[1] = interY;
        }

    }

    return result;
}
