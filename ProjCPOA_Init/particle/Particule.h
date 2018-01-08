#ifndef PARTICULE_H
#define PARTICULE_H

#include "Vector.h"

class Particule{
public:
    static float dt;
    static float gravite;

    float horloge;
    Vec2f pos;
    Vec2f vitesse;

    float futur_horloge;
    Vec2f futur_pos;
    Vec2f futur_vitesse;

    Particule();
    Particule(const Vec2f& v_pos,const Vec2f& v_vitesse):pos(v_pos),vitesse(v_vitesse){}

    void move();

};


#endif
