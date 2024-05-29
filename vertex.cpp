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

    int Vertex::getBuild(){
        return build;
    }

    bool Vertex::newSettel(int n, int typ, Player* pNew){

        if(build == 0){
            owner = n; 
            build = typ;
            delete p;
            p = pNew;
            return true;
        }
        else{
            cout << "this spote is taken please choose diffrent one" << endl;
            return false;
        }
    }

    bool Vertex::newCity(Player* pNew){

        if(build == 1 && pNew == p){
            build = 2;
            return true;
        }
        else{
            cout << "this spote is taken please choose diffrent one" << endl;
            return false;
        }
    }

    int Vertex::getOwner(){
        return this->owner;
    }

    void Vertex::getCards(string resource){
        if(build != 0 && p != nullptr){
            p->getCards(build, resource);
        }
    }

    int Vertex::getNum(){
        return num;
    }

    // void Vertex::setRoads(int r1, int r2, int r3){
    //     roads = {r1, r2, r3};
    // }

    // void Vertex::setRoads2(int r1, int r2){
    //     roads = {r1, r2};
    // }

    vector<int>& Vertex::gerRoads(){
        //cout << roads[0] << roads[1] << endl;
        return roads;
    }
                
}