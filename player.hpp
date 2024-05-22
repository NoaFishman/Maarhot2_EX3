/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace noa{

    class Player{

        string name;
        vector<int> resorce_cards;
        int points;
        int road_len;
        vector<int> structurs;

        public:

        Player(string new_name){
            this-> name = new_name;
            points = 0;
            road_len = 0;
            structurs = {5,4,15}; // 0=settlement 1=city 2=roade
            resorce_cards = {0,0,0,0,0};
        }
        
        Player(){
            this -> name = "new player";
            points = 0;
            road_len = 0;
            structurs = {5,4,15}; // 0=settlement  1=city 2=roade
            resorce_cards = {0,0,0,0,0};
        }

        string getName();
        int rollDice();
        void trade(Player p2, string give, string get, int amount_give, int amount_get);
        void endTurn();
        void placeRoad(vector<string> places, vector<int> placesNum);
        void placeSettelemnt();
        void buyDevelopmentCard();
        void printPoints();
        bool canSettel();
    };
}