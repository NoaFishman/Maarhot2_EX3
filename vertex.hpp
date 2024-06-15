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
        // this is the vertex class
        int owner; // the number of its owner
        int build; // 0= nothing 1= settel 2= city
        int num; // the numberof the vertex in the list in board
        Player* p; // pointer to the ver owner
        vector<int> roads; // vector of the numbers of the roads around it

        public:

            // constructor get the ver num and the roads num if hav 3 roads around
            Vertex(int n , int r1, int r2, int r3){
                build = 0;
                num = n;
                owner = 0;
                this->roads = {r1, r2, r3};
            }

            // constructor get the ver num and the roads num if hav 2 roads around
            Vertex(int n , int r1, int r2){
                build = 0;
                num = n;
                owner = 0;
                this->roads = {r1, r2};
            }

            // defult constructor
            Vertex(){
                build = 0;
                num = 0;
                owner = 0;
            }

            // copy constructor
            Vertex(const Vertex& other){
                owner = other.owner;
                build = other.build;
                num = other.num;
                p = other.p;
                roads = other.roads;

            }
            
            // operator "="
            Vertex& operator=(const Vertex& other) {
                if (this == &other){
                    return *this;
                }
                num = other.num;
                build = other.build;
                owner = other.owner;
                p = other.p;
                return *this;
            }

            // all the functions exlanations will be above each one of them in the cpp file
            bool newSettel(int n, int typ, Player* pNew);
            int getBuild();
            int getNum();
            int getOwner();
            void getCards(string resource);
            bool newCity(Player* pNew);
            vector<int>& gerRoads();
            string getVer();          
    };
}