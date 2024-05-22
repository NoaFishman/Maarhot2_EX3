/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include "player.hpp"
#include "board.hpp"
using namespace std;

namespace noa{

    class Catan{

        vector<Player> players;
        Board board;

        public:

            Catan(Player new_p1, Player new_p2, Player new_p3){
                players.push_back(new_p1);
                players.push_back(new_p2);
                players.push_back(new_p3);
                board.biuldBoard();
            }

            int ChooseStartingPlayer();
            Board getBoard();
            void printWinner();
            void placeSettelemnt(vector<string> places, vector<int> placesNum, int n);
            void placeRoad(vector<string> places, vector<int> placesNum, int n);
    };
    
}