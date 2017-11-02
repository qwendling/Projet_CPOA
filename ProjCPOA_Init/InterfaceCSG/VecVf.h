#ifndef VECVF_H
#define VECVF_H

#include "Array.h"

class VecVf: public Vec2<float>{
protected:
    Array<float,2> vitesse;
public:
    VecVf(){
        float dx = float(std::rand())/RAND_MAX;
        float dy = float(std::rand())/RAND_MAX;
        vitesse[0] = (dx-0.5f)/100.0f;
        vitesse[1] = (dy-0.5f)/100.0f;
    }

    inline void avance(float Ox=0,float Oy=0){
        float n = norme();
        data[0] += vitesse[0];
        data[1] += vitesse[1];

        if (n>1.414f)
        {
           data[0] = Ox;
           data[1] = Oy;
        }
    }
};


#endif
