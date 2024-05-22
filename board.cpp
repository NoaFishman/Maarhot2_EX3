/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include "board.hpp"
using namespace std;

namespace noa{

    void Board::biuldBoard(){
        vector<int> numbers = {0,0,1,2,2,2,2,0,2,2,2,2,1}; // th index is the number we need to place
        vector<int> resource = {3,3,4,4,4}; // 0 = Mountains, 1 = Hills, 2 = Fields, 3 = Forest, 4 = Pasture
        vector<string> places ={"Mountains", "Hills", "Fields", "Forest", "Pasture"};

        for(int i=0; i< 19; ++i){
            if(i == 9){
                hexa[i].setHex(0, 5); // represent the desert in the middle
            }
            else{
                int x1 = rand()%13;
                int x2 = rand()%5;
                while(numbers[x1] == 0){
                    x1 = (x1 + 1) %13;
                }
                while(resource[x2] == 0){
                    x2 = (x2 + 1) %5;
                }
                hexa[i].setHex(places[x2], x1);
                numbers[x1]--;
                resource[x2]--;
            }
        }
    }

    // return the vertex the player chose
    Vertex& Board::getVer(vector<string> places, vector<int> placesNum){
        for( int i=0; i<ver.size(); i++){
            if(ver[i].isThisVer(places, placesNum)){
                return ver[i];
            }
        }
        throw std::invalid_argument{"ther is no such vertex"}; // if the data we got isn't correct
    }
    
}