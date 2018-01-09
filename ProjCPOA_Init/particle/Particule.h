#ifndef PARTICULE_H
#define PARTICULE_H

#include "Vector.h"
#include "Image2Grey.h"
#include "GradientSobel.h"

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

    Image2Grey im;
    Image2D<Vec2f> gradient;

    Particule():horloge(0),im(0,0),gradient(0,0){id=nbId++;}
    Particule(const Vec2f& v_pos,const Vec2f& v_vitesse):horloge(0),pos(v_pos),vitesse(v_vitesse),im(0,0),gradient(0,0){id=nbId++;}
    bool operator<(Particule& p){
        return horloge < p.horloge;
    }

    void move();

    bool calcul_PtsImpact(Vec2f &P_impact);

    void initIm(Image2Grey& im,Image2D<Vec2f> gradient){
        this->im = im;
        this->gradient = gradient;
    }
};




#endif
