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

        public:

        Player(string new_name){
            name = new_name;
            points = 0;
            road_len = 0;
            structurs = {5,4,15}; // 0=settlement 1=city 2=roade
            resorce_cards = {0,0,0,0,0}; // 0 = 🪨Mountains, 1 = 🧱Hills, 2 = 🌾Fields, 3 = 🪵Forest, 4 = 🐑Pasture
        }
        
        Player(){
            name = "new player";
            points = 0;
            road_len = 0;
            structurs = {5,4,15}; // 0=settlement  1=city 2=roade
            resorce_cards = {0,0,0,0,0};
        }

        
        
        string getName();
        int rollDice();
        // void trade(Player p2, string give, string get, int amount_give, int amount_get);
        // void endTurn();
        void placeRoad();
        void placeSettelemnt();
        void buyDevelopmentCard();
        void printPoints();
        bool canSettel();
        bool canCity();
        bool canRoad();
        void getCards(int build, string resource);
        void whatsMyCards();
        int getPoints();
        void placeCity();
        void buyRoad();
        void buySettelment();
        void buyCity();
        void fourToOne(int from, int to);
        int numOfCards();
        void throwCards(int what, int how);
        void switchCards(int give, int take);
        bool canDo(int what, int how);
    };
}