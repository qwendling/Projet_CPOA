#include "Image2RGB.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;
Image2RGB Image2RGB::chargerPPM(const std::string& path){
    //On ouvre le fichier en lecture
    ifstream file(path,ios::in);

    int w,h,max;
    std::stringstream ss;

    //Si le fichier n'est pas ouvert on quitte
    if(file){
        std::string line;
        getline(file,line);
        //On verifie le magic number
        if(line != "P3")
            return Image2RGB(0,0);
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
        Image2RGB Result(w,h);
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
                Result(x,y)[0] = tmp * coeff ;
                data >> tmp;
                Result(x,y)[1] = tmp * coeff ;
                data >> tmp;
                Result(x,y)[2] = tmp * coeff ;
            }
        }
        file.close();
        return Result;
    }
    return Image2RGB(0,0);
}

void Image2RGB::sauvegarderPPM(const std::string& path)const{
    //On ouvre le fichier en lecture
    ofstream file(path,ios::out | ios::trunc);

    //Si le fichier n'est pas ouvert on quitte
    if(file){
        file << "P3" << endl;
        file << this->width() << " " << this->height() << endl;
        file << 255 << endl;
        for(uint y=0;y<this->height();y++){
            for(uint x=0;x<this->width();x++){
                file << (int)(*this)(x,y)[0] << " ";
                file << (int)(*this)(x,y)[1] << " ";
                file << (int)(*this)(x,y)[2] << " ";
            }
            file << endl;
        }
        file.close();
    }
}
