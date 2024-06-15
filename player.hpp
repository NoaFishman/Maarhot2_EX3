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

    // all the classes inhretence from player so this is here
    struct RandomInitializer{
        RandomInitializer(){
            std::srand(static_cast<unsigned int>(std::time(0)));
        }
    };


    class Player{

        string name = " ";
        vector<int> resorce_cards; // how many of each card this player have
        int points; // victory points
        int road_len; // to look for the longest road
        vector<int> structurs; // how many structur he have  that he can build
        vector<int> devCards; // how many dev card he have frome each typ

        public:

        // constructor
        Player(string new_name){
            name = new_name;
            points = 0;
            road_len = 0;
            structurs = {5,4,15}; // 0=settlement 1=city 2=roade
            resorce_cards = {0,0,0,0,0}; // 0 = 🪨Mountains, 1 = 🧱Hills, 2 = 🌾Fields, 3 = 🪵Forest, 4 = 🐑Pasture
            devCards = {0,0,0,0,0}; // represent how many cards the player have from each typ
        }
        
        // defult constructor
        Player(){
            name = "new player";
            points = 0;
            road_len = 0;
            structurs = {5,4,15}; // 0=settlement  1=city  2=roade
            resorce_cards = {0,0,0,0,0}; // 0 = 🪨Mountains, 1 = 🧱Hills, 2 = 🌾Fields, 3 = 🪵Forest, 4 = 🐑Pasture
            devCards = {0,0,0,0,0}; // represent how many cards the player have from each typ
        }

        // all the functions exlanations will be above each one of them in the cpp file
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