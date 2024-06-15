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
    // this test checking that the function thatchoose the first player is truly random
    // by run the function 100 time and see that all the player was chosen at least 20 times
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
    // this test checking that the creating of the board is truly random
    // by creat 2 boards and comper them 
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
    // this test is checking that when i build new settel it is stand with all the rules
    // 2 roads distance
    // just nex to your owne road
    // can't sattel on someone else settelment
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

TEST_CASE("dice random"){
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

TEST_CASE("road"){
    // this test checking that when i build new road it is stand with all the rules
    // next to you'r road or settelment or city
    // not on someone else road
    Player p1("noa");
    Player p2("omer");
    Board board;
    board.biuldBoardDemo();
    // first settelment
    board.canBuildSettelFirst(8, 1, &p1);
    board.canBuildSettelFirst(6, 2, &p2);
    Vertex* v8 = &board.getVer(8);
    Vertex* v7 = &board.getVer(7);
    Vertex* v5 = &board.getVer(5);
    Vertex* v6 = &board.getVer(6);
    bool flag = false;
    // there is no settelment or city in this road vertex
    if(board.canBuildRoad(*v5, *v7, 1) && board.newRoad(*v5, *v7,1)){
        flag = true;
    }
    CHECK(flag == false);
    flag = false;
    // this road isn't next to your settelment
    if(board.canBuildRoad(*v5, *v6, 1) && board.newRoad(*v5, *v6,1)){
        flag = true;
    }
    CHECK(flag == false);
    flag = false;
    // this road is good
    if(board.canBuildRoad(*v8, *v7, 1) && board.newRoad(*v8, *v7,1)){
        flag = true;
    }
    CHECK(flag == true);
    flag = false;
    // road next to other road
    if(board.canBuildRoad(*v5, *v7, 1) && board.newRoad(*v5, *v7,1)){
        flag = true;
    }
    CHECK(flag == true);
    flag = false;
    // road on other player road wont work
    if(board.canBuildRoad(*v5, *v7, 2) && board.newRoad(*v5, *v7,2)){
        flag = true;
    }
    CHECK(flag == false);
    flag = false;
}

TEST_CASE("city"){
    // this test checking that when i build new city it is stand al the rules
   Board b;
   b.biuldBoardDemo();
   Player p1("noa");
   Player p2("omer");
   Vertex* v8 = &b.getVer(8);
   Vertex* v7 = &b.getVer(7);
   Vertex* v6 = &b.getVer(6);
   b.canBuildSettelFirst(8, 1, &p1);
   b.canBuildSettelFirst(6, 1, &p2);
   // should be false there is no settelment in this vertex
   CHECK(v7->newCity(&p1) == false);
   // should be false p1 isn't the owner
   CHECK(v6->newCity(&p1) == false);
   // should be true
   CHECK(v8->newCity(&p1) == true);
}

TEST_CASE("buing + 4 to 1"){
    // all the action that player can do with his cards
   // 0 = 🪨Mountains, 1 = 🧱Hills, 2 = 🌾Fields, 3 = 🪵Forest, 4 = 🐑Pasture
   Player p1("noa");
   Player p2("omer");
   p1.getCards(2, "🧱");
   p1.getCards(2, "🪵");
   p1.getCards(3, "🌾");
   p1.getCards(3, "🪨");
   p1.getCards(1, "🐑"); 
   p2.getCards(1, "🧱");
   p2.getCards(2, "🪵");
   p2.getCards(1, "🌾");
   p2.getCards(3, "🪨");
   // BUY THINGS IF THE PLAYER HAVE OR NOT HAVING THE RESOURCE CARDS
   CHECK(p2.canSettel() == false);
   CHECK(p1.canSettel() == true);
   p1.buySettelment();
   p1.placeSettelemnt();
   CHECK(p2.canRoad() == true);
   p2.buyRoad();
   CHECK(p2.canCity() == false);
   CHECK(p1.canCity() == true);
   p1.buyCity();
   CHECK(p2.canDevelopCard() == false);
   p2.getCards(1, "🐑");
   CHECK(p2.canDevelopCard() == true);
   // switch 4 to one cards
   Player p3("roni");
   p3.getCards(4,"🐑");
   p3.getCards(1,"🪵");
   CHECK(p3.canRoad() == false);
   p3.fourToOne(4, 1);
   CHECK(p3.canRoad() == true);
}

TEST_CASE("development cards"){
    // for each dev card call the function to use it (sending vector of all the inputs) and see that it is really happened
    vector<int> input;
    vector<string>inputString;
    Player p1("noa");
    Player p2("omer");
    Player p3("roni");
    p2.getCards(3, "🧱");
    p3.getCards(3, "🧱");
    
    p1.getDevCard(0);
    p1.getDevCard(1);
    p1.getDevCard(2);
    p1.getDevCard(3);
    p1.getDevCard(4);
    Catan catan{p1, p2, p3, true};
    cout << "night - 0, year bless - 2, build two roads - 3, monopol - 4" << endl;
    inputString = {"omer"};
    input = {0, 1};
    // nghit
    bool flag = false;
    catan.useDevCardTest(0,0,0,0,0,&flag,input,inputString);
    CHECK(catan.getPlayer(0).haveCard(0) == false);
    //bless year
    int bless1 = 0;
    int bless2 = 0;
    int amountB1 = 0;
    int amountB2 = 0;
    input = {2, 2, 4 };
    catan.useDevCardTest(0,&bless1,&bless2,&amountB1,&amountB2,&flag,input,inputString);
    CHECK(catan.getPlayer(0).haveCard(2) == false);
    //2 roads
    catan.placeSettelemntFirst(8, 0);
    input = {3, 8,7,5,7};
    catan.useDevCardTest(0,&bless1,&bless2,&amountB1,&amountB2,&flag,input,inputString);
    CHECK(catan.getPlayer(0).haveCard(3) == false);
    //monopol
    input = {4, 2};
    catan.useDevCardTest(0,&bless1,&bless2,&amountB1,&amountB2,&flag,input,inputString);
    CHECK(catan.getPlayer(0).haveCard(4) == false);
}

TEST_CASE("points"){
    // for al the ptions to get point check if the player really get them
    Player p1("noa");
    Player p2("omer");
    p1.placeSettelemnt();
    CHECK(p1.getPoints() == 1);
    p1.buyCity();
    CHECK(p1.getPoints() == 2);
    p1.getDevCard(1);
    CHECK(p1.getPoints() == 3);
}