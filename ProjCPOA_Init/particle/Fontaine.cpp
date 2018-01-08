#include "Fontaine.h"


void Fontaine::move_all(){
    while(1){
        Particule* p = queue_particle.top();
        queue_particle.pop();
        if(p->horloge > horloge+dt){

            queue_particle.push(p);
            horloge = horloge+dt;
            std::cout << "fin move_all " << p->horloge << std::endl;
            return;
        }
        p->move();
        queue_particle.push(p);
        //std::cout << "fin move" << std::endl;
    }
}
