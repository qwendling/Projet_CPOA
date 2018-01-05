#include "csgRegularPolygon.h"

bool csgRegularPolygon::intersect(float, float) const{
    if(!this->intersectBBox(x,y)){
        return false;
    }
    Vec3f p_local = inverse*Vec3f(x,y,1);
    float distance_centre = p_local[0]*p_local[0]+p_local[1]*p_local[1];
    return distance_centre<=(0.5*0.5);
}

void csgRegularPolygon::init_liste_sommets(){
    Vec3f s = {0.5,0,1};
    Matrix33d matrice_rotate = Matrix33d::rotate(2*M_PI/nb_sommets);
    liste_sommets.push_back(s);
    for(int i=1;i<nb_sommets;i++){
        s = matrice_rotate * s;
        liste_sommets.push_back(s);
    }
}
