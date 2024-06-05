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
        vector<int> developmentCards;// represent the stack of development card

        public:

            Catan(Player& new_p1, Player& new_p2, Player& new_p3){
                players.push_back(new_p1);
                players.push_back(new_p2);
                players.push_back(new_p3);
                board.biuldBoard();
                board.boardStutus();
                developmentCards = {5,4,2,2,2}; // 0-nghit, 1-V point, 2-bless year, 3-build 2 road, 4-monopol 
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
            int getDevCard();
            void useDevCard(int n, int* bless1, int* bless2, int* amountB1, int* amountB2, bool* blessYear);
            void turnChoise(int n, int* bless1, int* bless2, int* amountB1, int* amountB2, bool* blessYear);
            void rollDice(int n);
    };
    
}