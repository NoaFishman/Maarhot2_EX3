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

    // return the hex num
    int Hex::getNum(){
        return num;
    }

    // return the hex num as a string (for the board status)
    string Hex::getNumString(){
        if(num < 10){
            // add " " so all the number will have the same amount of chars so the board print will be clear
            return " "+to_string(num);
        }
        else{
            return to_string(num);
        }
    }

    // return the resource
    string Hex::getPlace(){
        return resource;
    }

    // set the hex resource and number when we build the board
    void Hex::setHex(string typ, int value){
        num = value;
        resource = typ;
    }

    // retuen the number of the vertexes so the player who settel on them can get the resorces card
    vector<int>& Hex::getCards(){        
        return vertexes;
    }
}
