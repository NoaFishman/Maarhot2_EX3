/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
//#include "player.hpp"


using namespace std;

namespace noa{

    class Vertex{

        int owner =0; // change to player !!!!!!!!!!!!!!!!!!!!!!!!!!!
        int build; // 0= nothing 1= settel 2= city
        vector<Hex> hexa;

        public:

            Vertex(){
                build = 0;
            }

            void buildVer3(Hex& h1, Hex& h2, Hex& h3){
                hexa.push_back(h1);
                hexa.push_back(h2);
                hexa.push_back(h3);
            }

            void buildVer2(Hex& h1, Hex& h2){
                hexa.push_back(h1);
                hexa.push_back(h2);
            }

            void buildVer1(Hex& h1){
                hexa.push_back(h1);
            }

            // check if the data we got is the data of this vertex
            bool isThisVer(vector<string> places, vector<int> placesNum){
                bool flag;
                for( int i=0; i<hexa.size(); i++){
                    flag = false;
                    for(int j=0; j<places.size(); j++){
                        if(hexa[i].getNum() == placesNum[j] && hexa[i].getPlace() == places[j]){
                            flag = true;
                        }
                    }
                    if(!flag){
                        return false;
                    }
                }
                return true;
            }

            void newSettel(int n, int typ){
                owner = n; 
                build = typ;
            }

    };
}