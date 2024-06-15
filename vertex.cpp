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
    // return the 1 for settelment and 2 for city (0 for nothing)
    int Vertex::getBuild(){
        return build;
    }

    // check if no one owne this ver and if not build new settel 
    bool Vertex::newSettel(int n, int typ, Player* pNew){

        if(build == 0){
            owner = n; 
            build = typ;
            //delete p;
            p = pNew;
            //delete pNew;
            return true;
        }
        else{
            cout << "sorry but you can't build here"<< endl;
            //delete pNew;
            return false;
        }
    }

    // check that the player owne the ver and build city
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

    // return the owner number (by the order of the list in catan)
    int Vertex::getOwner(){
        return owner;
    }

    // update the player of this ver resource cards
    void Vertex::getCards(string resource){
        if(build != 0 && p != nullptr){
            p->getCards(build, resource);
        }
    }

    // return the ver number by the order  of the vertexes in the board list
    int Vertex::getNum(){
        return num;
    }

    // retuen the string as it will be shown in the map that printing
    string Vertex::getVer(){
        if(owner == 0){
            if(build == 0){
                if(num < 10){
                    return " "+to_string(num);
                }
                else{
                    return to_string(num);
                }
            }
            else if(build == 1){
                return "\033[1;31m◯ \033[0m";

            }
            else if(build == 2){
                return "\033[31m⬤ \033[0m";
            }
        }
        else if(owner == 1){
            if(build == 0){
                if(num < 10){
                    return " "+to_string(num);
                }
                else{
                    return to_string(num);
                }
            }
            else if(build == 1){
                return "\033[1;33m◯ \033[0m";

            }
            else if(build == 2){
                return "\033[33m⬤ \033[0m";
            }

        }
        else if(owner == 2){
            if(build == 0){
                if(num < 10){
                    return " "+to_string(num);
                }
                else{
                    return to_string(num);
                }
            }
            else if(build == 1){
                return "\033[1;34m◯ \033[0m";
            }
            else if(build == 2){
                return "\033[34m⬤ \033[0m";

            }

        }
        return "";
    }

    // return the vector of numbers that the roads of this ver
    vector<int>& Vertex::gerRoads(){
        return roads;
    }
                
}