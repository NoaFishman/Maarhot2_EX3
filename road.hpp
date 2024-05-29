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

        public:

            Road(Vertex& nv1, Vertex& nv2){
                v1 = nv1;
                v2 = nv2;
                numV1 = nv1.getNum();
                numV2 = nv2.getNum();
                path  = false;
                owner = 3;
            }

            bool isThisRoad(Vertex& nv1, Vertex& nv2);
            bool isTaken();
            void setRoad(int owmer1);
            int getOwner();

    };
}