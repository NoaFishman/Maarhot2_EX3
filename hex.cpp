/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include "hex.hpp"
using namespace std;

namespace noa{

    int Hex::getNum(){
        return num;
    }

    string Hex::getNumString(){
        if(num < 10){
            return " "+to_string(num);
        }
        else{
            return to_string(num);
        }
    }

    string Hex::getPlace(){
        return resource;
    }

    void Hex::setHex(string typ, int value){
        num = value;
        resource = typ;
    }


    vector<int>& Hex::getCards(){        
        return vertexes;
    }
}
