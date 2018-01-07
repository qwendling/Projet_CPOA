#include "csgRegularPolygon.h"

bool csgRegularPolygon::intersect(float x, float y) const{
    if(!this->intersectBBox(x,y)){
        return false;
    }
    Vec2f p_local = inverse*Vec3f({x,y,1});
    for(std::vector<Vec2f>::const_iterator it=liste_sommets.begin();it!=liste_sommets.end();++it){
        Vec2f p1 =*it;
        Vec2f p2;
        if(std::next(it) == liste_sommets.end()){
            p2=*liste_sommets.begin();
        }else{
            p2=*std::next(it);
        }
        Vec2f v1=p2-p1;
        Vec2f v2=p_local-p1;
        if(vect(v1,v2)<0)
            return false;
    }
    return true;
}

void csgRegularPolygon::init_liste_sommets(){
    Vec2f s = {0.5,0};
    Matrix33d matrice_rotate = Matrix33d::rotate(2*M_PI/nb_sommets);
    liste_sommets.push_back(s);
    for(int i=1;i<nb_sommets;i++){
        s = matrice_rotate * Vec3f({s[0],s[1],1});
        liste_sommets.push_back(s);
    }
}
