#include "Particule.h"


static float Particule::dt = 0.001;
static float Particule::gravite = 9.81;


void Particule::move(){
    while(1){
        futur_horloge = horloge+dt;
        futur_pos = futur_horloge*vitesse + pos + gravite/2.f*futur_horloge*futur_horloge;
        futur_vitesse = vitesse + gravite*futur_horloge;

        Vec2f diff_pos = pos-futur_pos;
        if(abs(diff_pos[0]) >= 1 || abs(diff_pos[1]) >= 1){
            return;
        }
    }
}
