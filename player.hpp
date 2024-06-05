/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>

using namespace std;

namespace noa{

    class Player{

        string name = " ";
        vector<int> resorce_cards;
        int points;
        int road_len;
        vector<int> structurs;
        vector<int> devCards;

        public:

        Player(string new_name){
            name = new_name;
            points = 0;
            road_len = 0;
            structurs = {5,4,15}; // 0=settlement 1=city 2=roade
            resorce_cards = {0,0,0,0,0}; // 0 = 🪨Mountains, 1 = 🧱Hills, 2 = 🌾Fields, 3 = 🪵Forest, 4 = 🐑Pasture
            devCards = {0,0,0,0,0}; // represent how many cards the player have from each typ
        }
        
        Player(){
            name = "new player";
            points = 0;
            road_len = 0;
            structurs = {5,4,15}; // 0=settlement  1=city  2=roade
            resorce_cards = {0,0,0,0,0};
            devCards = {0,0,0,0,0}; // represent how many cards the player have from each typ
        }

        
        
        string getName();

        int rollDice();

        void placeRoad();
        bool canRoad();
        void buyRoad();

        void placeSettelemnt();
        bool canSettel();
        void buySettelment();

        void buyDevelopmentCard();
        bool canDevelopCard();
        void getDevCard(int x);
        bool haveCard(int x);
        void useDevCard(int x);
        int takeYourResorce(int reso);
        void addResoCard(int how, int what);
        int getResorceAmont(int reso);
        void printDevCards();
        int totalDevCards();

        bool canCity();
        void buyCity();

        int getPoints();
        void getCards(int build, string resource);
        void whatsMyCards();
        int numOfCards();
        void throwCards(int what, int how);
        void fourToOne(int from, int to);
        void switchCards(int give, int take);
        bool canDo(int what, int how);
    };
}