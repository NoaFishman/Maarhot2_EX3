/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
//#include "player.hpp"
#include "board.hpp"
using namespace std;

namespace noa{

    class Catan{

        vector<Player> players;
        Board board;

        public:

            Catan(Player& new_p1, Player& new_p2, Player& new_p3){
                players.push_back(new_p1);
                players.push_back(new_p2);
                players.push_back(new_p3);
                board.biuldBoard();
                board.printBoard();
            }

            ~Catan(){}

            int ChooseStartingPlayer();
            Board getBoard();
            bool isWinner();
            void placeSettelemntFirst(int verNum, int n);
            void placeSettelemnt(int verNum, int n);
            void placeRoad(int verNum, int verNum2, int n);
            void placeCity(int verNum, int n);
            string getPlayerName(int n);
            void getCards();
            void cardStutus();
            void pointStutus();
            void turn(int n);
    };
    
}