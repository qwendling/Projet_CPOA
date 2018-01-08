#ifndef PARTICULE_H
#define PARTICULE_H

#include "Vector.h"
#include "Image2Grey.h"

class Particule{
public:
    static float dt;
    static float gravite;

    float horloge;
    Vec2f pos;
    Vec2f vitesse;


    int id;
    static int nbId;

    float futur_horloge;
    Vec2f futur_pos;
    Vec2f futur_vitesse;

    Particule():horloge(0){id=nbId++;}
    Particule(const Vec2f& v_pos,const Vec2f& v_vitesse):horloge(0),pos(v_pos),vitesse(v_vitesse){id=nbId++;}
    bool operator<(Particule& p){
        return horloge < p.horloge;
    }

    void move(const Image2Grey&);

    bool calcul_PtsImpact(const Image2Grey&,Vec2f &P_impact);

};




#endif
