#ifndef CSGREGULARPOLYGON_H
#define CSGREGULARPOLYGON_H
#include "csgPrimitive.h"
#include <vector>
#include <math.h>

class csgRegularPolygon : public csgPrimitive{
public:
    int nb_sommets;
    csgRegularPolygon():csgPrimitive(),nb_sommets(3){
        init_liste_sommets();
    }
    csgRegularPolygon(int nb):csgPrimitive(),nb_sommets(nb){
        init_liste_sommets();
    }
    csgRegularPolygon(const csgRegularPolygon& cp) : csgPrimitive(cp){
        nb_sommets = cp.getNb_sommets();
        init_liste_sommets();
    }
    bool intersect(float, float) const;
    int getNb_sommets(){return this->nb_sommets;}
    void init_liste_somemts();
private:
    int nb_sommets;
    std::vector<Vec3f> liste_sommets;
    void init_liste_sommets();
};




#endif
