#include "Image2Grey.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;
Image2Grey Image2Grey::chargerPGM(const std::string& path){
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
            return Image2Grey(0,0);
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
        Image2Grey Result(w,h);
        int tmp;
        double coeff = 1;
        std::stringstream data;
        string data_str;
        //On stock les donnees de l'image
        while(getline(file,line)){
            data_str += line+" ";
        }
        data.str(data_str);
        for(int y=0;y<h;y++){
            for(int x = 0;x<w;x++){
                data >> tmp;
                Result(x,y) = tmp * coeff ;
            }
        }
        file.close();
        return Result;
    }
    return Image2Grey(0,0);
}

void Image2Grey::sauvegarderPGM(const std::string& path) const{
    //On ouvre le fichier en lecture
    ofstream file(path,ios::out | ios::trunc);

    //Si le fichier n'est pas ouvert on quitte
    if(file){
        file << "P2" << endl;
        file << this->width() << " " << this->height() << endl;
        file << 255 << endl;
        for(uint y=0;y<this->height();y++){
            for(uint x=0;x<this->width();x++){
                file << (int)(*this)(x,y) << " ";
            }
            file << endl;
        }
        file.close();
    }
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


Image2Grey Image2Grey::sousEch(){
   Image2Grey result(this->width()>>1,this->height()>>1);

   for(uint i=0;i<result.width();i++){
       for(uint j=0;j<result.height();j++){
           result(i,j) = ((*this)(i<<1,j<<1)+(*this)((i<<1)+1,j<<1)+(*this)(i<<1,(j<<1)+1)+(*this)((i<<1)+1,(j<<1)+1))/4;
       }
   }

   return result;
}

Image2Grey Image2Grey::lissage(int n)const{
    Image2Grey result(*this);
    int size = 2*n+1;
    for(uint i=0;i<result.width();i++){
        for(uint j = 0;j<result.height();j++){
            int inter = 0;
            for(int x=-n;x<size-n;x++){
                for(int y=-n;y<size-n;y++){
                    if(i+x < 0 || j+y < 0 || i+x >= result.width() || j+y >= result.height())
                        continue;
                    inter += (*this)(i+x,j+y);
                }
            }
            result(i,j) = inter/(std::pow(size,2));
        }

    }
    return result;
}

void Image2Grey::seuillage(const int seuil){
    for(uint i=0;i<height();i++){
        for(uint j=0;j<width();j++){
            if((*this)(i,j)<seuil)
                (*this)(i,j) = 0;
            else
                (*this)(i,j) = 255;
        }
    }
}




