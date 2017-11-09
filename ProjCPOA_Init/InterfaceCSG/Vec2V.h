#ifndef VEC2V_H
#define VEC2V_H

#include "Vec2.h"

class Vec2V:public Vec2<float>{
    public:
        Vec2V();

    protected:
        Array<float,2> vitesse;

};


#endif
