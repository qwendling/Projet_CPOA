#ifndef FONTAINE_H
#define FONTAINE_H

#include "Particule.h"
#include "Image2Grey.h"
#include <queue>

class FoncteurParticule{
public:
    FoncteurParticule(){}
    bool operator()(const Particule* p1,const Particule* p2){
        return p1->horloge > p2->horloge;
    }
};

class Fontaine{
public:
    float dt;
    float horloge;
    std::priority_queue<Particule*,std::vector<Particule*>,FoncteurParticule> queue_particle;
    Fontaine():dt(0.1),horloge(0){}
    void append(Particule* p){queue_particle.push(p);}
    void move_all(const Image2Grey&);
};


#endif
