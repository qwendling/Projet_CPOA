#include "Matrix33d.h"


std::ostream &operator<<(std::ostream &out,const Matrix33d& m){
    out << '{';
    for(int i=0;i<3;i++){
        out << ", " << m[i] << "\n";
    }
    out << '}';
    return out;
}
