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
        // this is the road class
        Vertex v1; // the vertexes of the road
        Vertex v2;
        int numV1; // the numbers of the vertexes 
        int numV2;
        bool path; // is somone owne it (ther is player that his num is 0 and 0 mean also that no one bought it)
        int owner; // who is the owner
        string typ; // strin that represent the road ond the direction

        public:

            // constractor
            Road(Vertex& nv1, Vertex& nv2, string t){
                v1 = nv1;
                v2 = nv2;
                numV1 = nv1.getNum();
                numV2 = nv2.getNum();
                path  = false;
                owner = 3;
                typ = t;
            }

            // copy constructor
            Road(const Road& other){
                v1 = other.v1;
                v2 = other.v2;
                numV1 = other.numV1;
                numV2 = other.numV2;
                path  = other.path;
                owner = other.owner;
                typ = other.typ;
            }

            // all the functions exlanations will be above each one of them in the cpp file
            bool isThisRoad(Vertex& nv1, Vertex& nv2);
            bool isTaken();
            void setRoad(int owmer1);
            int getOwner();
            int getTheOtherVer(int vorg);
            string getRoad();

    };
}