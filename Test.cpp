/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include "doctest.h"
#include "catan.hpp"
#include <sstream>

using namespace std;
using namespace noa;

RandomInitializer randomInitializer;

TEST_CASE("Choosing starting player"){
    Player p1("noa");
    Player p2("omer");
    Player p3("roni");
    Catan catan{p1, p2, p3, true};
    vector<int> counter = {0,0,0};
    for(int i=0; i<100; i++){
        int temp = catan.ChooseStartingPlayer();
        counter[temp]++;
    }
    CHECK(counter[0]>20);
    CHECK(counter[1]>20);
    CHECK(counter[2]>20);
}

TEST_CASE("Random board"){
    cout << "here"<< endl;
    Board board1;
    cout << "noa"<< endl;
    board1.biuldBoard();
    cout << "here2"<< endl;
    Board board2;
    board2.biuldBoard();
    cout << "here"<< endl;
    vector<Hex> hex1 = board1.getHex();
    vector<Hex> hex2 = board2.getHex();
    bool flag = true;
    for(int i=0; i<hex1.size(); i++){
        CHECK(hex1[i].getPlace() != hex2[i].getPlace());
        
        if(hex1[i].getPlace() != hex2[i].getPlace()){
            flag =false;
        }
        if(hex1[i].getNum() != hex2[i].getNum()){
            flag = false;
        }
    }
    CHECK(flag == false);
}
