#include "Image2Grey.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
void Image2Grey::chargerPGM(const std::string& path){
    //On ouvre le fichier en lecture
    ifstream file(path,ios::in);

    int w,h,max;
    std::stringstream ss;

    //Si le fichier n'est pas ouvert on quitte
    if(file){
        std::string line;
        getline(file,line);
        //On verifie le magic number
        if(line != "P2")
            return;
        //On enregistre les parametre du ficher
        while(getline(file,line)){
            if(line[0] == '#'){
                continue;
            }
            ss.str(line);
            ss >> w;
            ss >> h;
            getline(file,line);

            ss.seekg(0);
            ss.str(line);
            ss >> max;
            break;
        }
        w_=w;
        h_=h;
        pixels_ = new unsigned char[w*h];
        int j=0;
        //On stock les donees de l'image
        while(getline(file,line)){
            ss.seekg(0);
            ss.str(line);
            for(int i=0;i<w;i++){
                ss >> tmp;
                (*this)(i,j) = tmp * coeff;
            }
            j++;
        }
        file.close();
    }
}

void sauvegarderPGM(const std::string& path){

}

std::ostream &operator<<(std::ostream &out,const Image2Grey& i){
    for(uint y = 0;y<i.height();y++){
        for(uint x = 0;x<i.width();x++){
            out << (int)i(x,y) << " ";
        }
        out << std::endl;
    }
    return out;
}
