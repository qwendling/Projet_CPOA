#include "Particule.h"


float Particule::dt = 0.001;
float Particule::gravite = -9.81;


void Particule::move(){
    while(1){
        futur_horloge = horloge+dt;
        float tmp_grav = gravite/2.f*futur_horloge*futur_horloge;
        futur_pos = futur_horloge*vitesse + pos + Vec2f({tmp_grav,tmp_grav});
        float tmp_grav2 = gravite*futur_horloge;
        futur_vitesse = vitesse + Vec2f({tmp_grav2,tmp_grav2});


        Vec2f diff_pos = pos-futur_pos;
        horloge = futur_horloge;
        pos = futur_pos;
        vitesse = futur_vitesse;
        //std::cout << diff_pos << std::endl;
        if(abs(diff_pos[0]) >= 1 || abs(diff_pos[1]) >= 1){
            return;
        }
    }
}
