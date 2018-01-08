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

    Particule():horloge(0){}
    Particule(const Vec2f& v_pos,const Vec2f& v_vitesse):pos(v_pos),vitesse(v_vitesse){}
    bool operator<(Particule& p){
        return horloge < p.horloge;
    }

    void move();

};


#endif
