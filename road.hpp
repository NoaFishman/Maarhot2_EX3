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

        public:

            Road(Vertex& nv1, Vertex& nv2){
                v1 = nv1;
                v2 = nv2;
            }

    };
}