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

    // check ifthis 2 vertex are the vertexes of this road
    bool Road::isThisRoad(Vertex& nv1, Vertex& nv2){
        if(v1.getNum() == nv1.getNum() && v2.getNum() == nv2.getNum() ){
            return true;
        }
        if(v2.getNum() == nv1.getNum() && v1.getNum() == nv2.getNum() ){
            return true;
        }
        return false;
    }
    
    // change this road owner if no one owne it yet
    void Road::setRoad(int owner1){
        if(path == true){
            cout << "sorry but this road is taken" << endl; // LOL
        }
        else{
            owner = owner1;
            path = true;
        }
    }

    // return the owner number
    int Road::getOwner(){
        return owner;
    }

    // return if this road is taken (lol)
    bool Road::isTaken(){
        return path;
    }

    // get number of ver of this road and return the number the seconde ver
    int Road::getTheOtherVer(int vorg){
        if(vorg == numV1){
            return numV2;
        }
        return numV1;
    }

    // return a string that represent this road
    string Road::getRoad(){
        if(!path){
            return typ;
        }
        if(owner == 0){
            return "\033[1;31m"+typ+"\033[0m";
        }
        else if(owner == 1){
            return "\033[1;33m"+typ+"\033[0m";
        }
        else if(owner == 2){
            return "\033[1;34m"+typ+"\033[0m";
        }
        return typ;
    }

}
