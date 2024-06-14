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

    vector<int>& Vertex::gerRoads(){
        return roads;
    }
                
}