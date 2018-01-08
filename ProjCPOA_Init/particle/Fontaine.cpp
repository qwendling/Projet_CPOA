#include "Fontaine.h"


void Fontaine::move_all(const Image2Grey& im){
    while(1){
        Particule* p = queue_particle.top();
        queue_particle.pop();
        if(p->horloge > horloge+dt){

            queue_particle.push(p);
            horloge = horloge+dt;
            return;
        }
        p->move(im);
        queue_particle.push(p);
    }
}
