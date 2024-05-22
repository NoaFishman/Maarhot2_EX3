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

    class Hex{

        int num;
        string resource;
        vector<Vertex> vextexes;

        public:

            Hex(){
                num =0;
            }

            Hex(string typ, int value){
                num = value;
                resource = typ;
            }

            int getNum(){
                return num;
            }

            string getPlace(){
                return resource;
            }

            void setHex(string typ, int value){
                num = value;
                resource = typ;
            }

            void buildHex(Vertex& v1, Vertex& v2, Vertex& v3, Vertex& v4, Vertex& v5, Vertex& v6){
                vextexes.push_back(v1);
                vextexes.push_back(v2);
                vextexes.push_back(v3);
                vextexes.push_back(v4);
                vextexes.push_back(v5);
                vextexes.push_back(v6);
            }
    };

    
}