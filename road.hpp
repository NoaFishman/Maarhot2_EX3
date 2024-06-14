/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include "vertex.hpp"

using namespace std;

namespace noa{

    class Road{

        Vertex v1;
        Vertex v2;
        int numV1;
        int numV2;
        bool path;
        int owner; 
        string typ;

        public:

            Road(Vertex& nv1, Vertex& nv2, string t){
                v1 = nv1;
                v2 = nv1;
                numV1 = nv1.getNum();
                numV2 = nv2.getNum();
                path  = false;
                owner = 3;
                typ = t;
            }

            Road(const Road& other){
                v1 = other.v1;
                v2 = other.v2;
                numV1 = other.numV1;
                numV2 = other.numV2;
                path  = other.path;
                owner = other.owner;
                typ = other.typ;
            }

            //~Road(){}

            bool isThisRoad(Vertex& nv1, Vertex& nv2);
            bool isTaken();
            void setRoad(int owmer1);
            int getOwner();
            int getTheOtherVer(int vorg);
            string getRoad();

    };
}