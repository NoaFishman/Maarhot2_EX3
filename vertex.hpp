/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include "player.hpp"


using namespace std;

namespace noa{

    class Vertex{

        int owner; // change to player !!!!!!!!!!!!!!!!!!!!!!!!!!!
        int build; // 0= nothing 1= settel 2= city
        int num;
        Player* p;
        vector<int> roads;

        public:

            Vertex(int n , int r1, int r2, int r3){
                build = 0;
                num = n;
                owner = 0;
                this->roads = {r1, r2, r3};
            }

            Vertex(int n , int r1, int r2){
                build = 0;
                num = n;
                owner = 0;
                this->roads = {r1, r2};
            }

            Vertex(){
                build = 0;
                num = 0;
                owner = 0;
            }

            Vertex(const Vertex& other){
                owner = other.owner;
                build = other.build;
                num = other.num;
                p = other.p;
                roads = other.roads;
            }

            ~Vertex(){
                delete p;
            }
            Vertex& operator=(const Vertex& other) {
                
                if (this==&other)
                    return *this;
               
                num = other.num;
                build = other.build;
                owner = other.owner;
                p = other.p;
                return *this;
            }

            bool newSettel(int n, int typ, Player* pNew);
            int getBuild();
            int getNum();
            int getOwner();
            void getCards(string resource);
            bool newCity(Player* pNew);
            // void setRoads(int r1, int r2, int r3);
            // void setRoads2(int r1, int r2);
            vector<int>& gerRoads();
            
                        
    };
}