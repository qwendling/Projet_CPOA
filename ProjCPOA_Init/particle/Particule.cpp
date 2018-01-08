#include "Particule.h"


float Particule::dt = 0.001;
float Particule::gravite = 9.81;
int Particule::nbId=0;


void Particule::move(const Image2Grey& im){
    Vec2f debut_pos=pos;
    while(1){
        futur_horloge = horloge+dt;
        float tmp_grav = (gravite/2.f)*dt*dt;
        futur_pos = dt*vitesse + pos + Vec2f({0.f,tmp_grav});
        float tmp_grav2 = gravite*dt;
        futur_vitesse = vitesse + Vec2f({0.f,tmp_grav2});


        Vec2f diff_pos = debut_pos-futur_pos;

        if(abs(diff_pos[0]) >= 1 || abs(diff_pos[1]) >= 1){
            Vec2f P_impact;
            horloge = futur_horloge;
            while(calcul_PtsImpact(im,P_impact)){
                futur_pos = P_impact + futur_vitesse*dt;
            }

            vitesse = futur_vitesse;
            pos = futur_pos;

            return;
        }
        horloge = futur_horloge;
        pos = futur_pos;
        vitesse = futur_vitesse;
    }
}

bool Particule::calcul_PtsImpact(const Image2Grey& im,Vec2f& P_impact){
    if(futur_pos[1]>=im.height()){
        futur_vitesse[0] = 0.9*futur_vitesse[0];
        futur_vitesse[1] = -0.5*futur_vitesse[1];
        P_impact = futur_pos;
        P_impact[1]=im.height()-1;
        return true;
    }

    if(futur_pos[1]<0){
        futur_vitesse[0] = 0.9*futur_vitesse[0];
        futur_vitesse[1] = -0.5*futur_vitesse[1];
        P_impact = futur_pos;
        P_impact[1]=0;
        return true;
    }

    if(futur_pos[0]<0){
        futur_vitesse[0] = -0.5*futur_vitesse[0];
        futur_vitesse[1] = 0.9*futur_vitesse[1];
        P_impact = futur_pos;
        P_impact[0]=0;
        return true;
    }

    if(futur_pos[0]<im.width()){
        futur_vitesse[0] = -0.5*futur_vitesse[0];
        futur_vitesse[1] = 0.9*futur_vitesse[1];
        P_impact = futur_pos;
        P_impact[1]=im.width()-1;
        return true;
    }


    return false;
}
