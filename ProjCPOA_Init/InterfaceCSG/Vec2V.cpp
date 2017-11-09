#include "Vec2V.h"

Vec2V::Vec2V(){
    float dx = float(std::rand())/RAND_MAX;
    float dy = float(std::rand())/RAND_MAX;
    vitesse[0] = (dx-0.5f);
    vitesse[1] = (dy-0.5f);
}


