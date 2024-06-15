/*
 * ID: 319055430
 * Email: noa.fishman@gmail.com
 */
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "catan.hpp"
using namespace std;
using namespace noa;

// the main file for the game
int main()
{
    string name1= "";
    cout << "welcome to the catan game, lets get started..." << endl;
    cout << "please enter the names of the 3 players: " << endl;
    // get the names from the user and create 3 players with the names i got
    cin >> name1;
    Player p1(name1);
    cin >> name1;
    Player p2(name1);
    cin >> name1;
    Player p3(name1);

    
    // create the board and start the game
    Catan catan{p1, p2, p3};

    int n = catan.ChooseStartingPlayer();

    int org = n;

    // first rount each player choose where to put his first settelment and then his second road
    for(int i=0; i<3; i++){

        cout << catan.getPlayerName(n) <<" choose where you want your first settlement" << endl;
        int verNum;
        cin >> verNum;
        catan.placeSettelemntFirst(verNum, n);

        cout << catan.getPlayerName(n) <<" choose where you want your first road" << endl;
        int verNum2;
        cin >> verNum2;
        catan.placeRoad(verNum, verNum2, n);
        n = (n + 1) %3;
    }

    // second round from the last player to the first choosing where to put the second road and then the second settelment
    for(int i=0; i<3; i++){

        n = ((n - 1 + 3) % 3);

        cout << catan.getPlayerName(n) <<" choose where you want your seconde road" << endl;
        int verNum;
        cin >> verNum;
        int verNum2;
        cin >> verNum2;
        catan.placeRoad(verNum, verNum2, n);

        cout << catan.getPlayerName(n) <<" choose where you want your second settlement" << endl;
        int verNumNew;
        cin >> verNumNew;
        catan.placeSettelemntFirst(verNumNew, n);

    }

    // update all the player resource cards and the the points and card status
    catan.getCards();
    cout << endl;
    catan.cardStutus();
    cout << endl;
    catan.pointStutus();
    cout << endl;

    // opening new teminal window to print there all the Instructions
    system("gnome-terminal -- bash -c 'cat mypipe; exec bash'");
    std::ofstream pipe("mypipe");
    
    if (pipe.is_open()) {

        // printing all the Instructions in the seconde window so the player will always be able to see them
        pipe << "this is the map of the action you can preform in you'r turn:"<< endl << endl;
        
        pipe << "0 - finish your turn"<< endl;
        pipe << "1 - new road"<< endl;
        pipe << "2 - new settelment"<< endl;
        pipe << "3 - upgrade settelment to city"<< endl;
        pipe << "4 - buy development card"<< endl;
        pipe << "5 - use development card"<< endl;
        pipe << "6 - cange 4 to 1"<< endl;
        pipe << "7 - show the board status"<< endl;
        pipe << "8 - switch cards with another player"<< endl;
        pipe << "9 - print the points status"<< endl;
        pipe << "10- print the cards status"<< endl << endl;

        pipe << "Building Cost:"<< endl <<endl;
        pipe << "Road-             🧱🪵"<< endl;
        pipe << "Settelment-       🧱🪵🌾🐑" << endl;
        pipe << "City-             🌾🌾🪨🪨🪨" << endl;
        pipe << "Development Card- 🌾🐑🪨" << endl;

        pipe.close();
        
    }

    // start the game in each itarreate check if one of the players have 10 points and if someone have sp finish the turn
    while(!catan.isWinner()){
        // call ing the turn function for the player
        catan.turn(org);
        // there is 3 player so if we want to move to the next one we will do %3
        org = (org + 1) % 3;
    }

    
    return 0;

}