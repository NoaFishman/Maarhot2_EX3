/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include "road.hpp"

using namespace std;

namespace noa{

    bool Road::isThisRoad(Vertex& nv1, Vertex& nv2){
        if(v1.getNum() == nv1.getNum() && v2.getNum() == nv2.getNum() ){
            return true;
        }
        if(v2.getNum() == nv1.getNum() && v1.getNum() == nv2.getNum() ){
            return true;
        }
        return false;
    }
    
    void Road::setRoad(int owner1){
        if(path == true){
            cout << "sorry but this road is taken" << endl; // LOL
        }
        else{
            owner = owner1;
            path = true;
        }

    }

    int Road::getOwner(){
        return owner;
    }

    bool Road::isTaken(){
        return path;
    }

}
