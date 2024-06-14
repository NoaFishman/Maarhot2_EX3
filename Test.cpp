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

TEST_CASE("Choosing starting player")
{
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
    catan.getBoard().boardStutus();
    
}

TEST_CASE("Random board")
{
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
        if(hex1[i].getPlace() != hex2[i].getPlace()){
            flag =false;
        }
        if(hex1[i].getNum() != hex2[i].getNum()){
            flag = false;
        }
    }
    CHECK(flag == false);
}

TEST_CASE("setelment"){
    Player p1("noa");
    Player p2("omer");
    Board board;
    board.biuldBoardDemo();
    // first settelment
    board.canBuildSettelFirst(8, 1, &p1);
    CHECK(board.getVer(8).getOwner() == 1);
    // you cant settel one road apart
    CHECK(board.canBuildSettelFirst(7, 1, &p1) == false);
    // you cant settel if some one else there
    CHECK(board.canBuildSettelFirst(8, 2, &p2) == false);
}

TEST_CASE("Choosing starting player"){
    // I check for each number if it roll more times then its probability
    Player p1("noa");
    vector<int> counter = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<200; i++){
        int temp = p1.rollDice();
        counter[temp]++;
    }
    CHECK(counter[0] == 0);
    CHECK(counter[1] == 0);
    CHECK(counter[2] >= 2);
    CHECK(counter[3] >= 5);
    CHECK(counter[4] >= 7);
    CHECK(counter[5] >= 10);
    CHECK(counter[6] >= 13);
    CHECK(counter[7] >= 16);
    CHECK(counter[8] >= 13);
    CHECK(counter[9] >= 10);
    CHECK(counter[10] >= 7);
    CHECK(counter[11] >= 5);
    CHECK(counter[12] >= 2);
}

