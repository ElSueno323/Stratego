#include "mapreader.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
mapReader::mapReader()
{

}
void mapReader::init(int p){

    ifstream p1("../../Stratego/map/p"+std::to_string(p)+".txt");
    string ligne;

    if(p1.is_open()){
        int i=0;
        int j = 0;
        while(p1 >> ligne){

            map[i][j]=ligne;

            i++;
            if(i == 10){
                i = 0;
                j++;
            }

        }
        p1.close();
    }else{
        std::invalid_argument("Pas de fichier trouvé");
    }

}


string mapReader::getValueOf(int x ,int y) const{
    return map[x][y];
}
