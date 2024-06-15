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

    class Hex{
        // hexagon on the board so ther is number, resorce and which vertexes number are on its edges
        int num;
        string resource = " ";
        vector<int> vertexes;

        public:

            // constructor that get the tertexes numbers (in their order in the ve lint in board)
            Hex(int v1, int v2, int v3, int v4, int v5, int v6){
                num =0;
                this->vertexes = {v1,v2,v3,v4,v5,v6};  // Clear existing elements to avoid accumulation
            }

            // copy constructor
            Hex(const Hex& other){
                num = other.num;
                resource = other.resource;
                vertexes = {other.vertexes[0], other.vertexes[1], other.vertexes[2], other.vertexes[3], other.vertexes[4], other.vertexes[5]};
            }
            
            // all the functions exlanations will be above each one of them in the cpp file
            int getNum();
            string getPlace();
            void setHex(string typ, int value);
            vector<int>& getCards();
            string getNumString();
    };

    
}