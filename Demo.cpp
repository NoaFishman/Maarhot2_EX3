/**
 * Demo file for Ex3.
 *
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
using namespace std;
using namespace noa;

int main()
{
    cout << "welcome to the catan game, lets get started..." << endl;
    cout << "please enter the names of the 3 players: " << endl;
    // get the names from the user and create 3 players with the names i got
    Player p1("noa");
    Player p2("omer");
    Player p3("roni");
    Catan catan(p1, p2, p3, true);
    // Starting of the game. Every player places two settlements and two roads.
    int n = catan.ChooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.

    int org = n;

    vector<int> input = {5, 6, 18, 25, 39, 40, 35, 40, 20, 25, 26, 44, 6, 4, 37};
    int j =0;

    for(int i=0; i<3; i++){

        cout << catan.getPlayerName(n) <<" choose where you want your first settlement" << endl;
        catan.placeSettelemntFirst(input[j], n);
        j++;
        cout << catan.getPlayerName(n) <<" choose where you want your first road" << endl;
        catan.placeRoad(input[j-1], input[j], n);
        j++;
        n = (n + 1) %3;
    }


    for(int i=0; i<3; i++){

        n = ((n - 1 + 3) % 3);

        cout << catan.getPlayerName(n) <<" choose where you want your seconde road" << endl;
        int verNum = input[j];
        j++;
        int verNum2 = input[j];
        j++;
        catan.placeRoad(verNum, verNum2, n);

        cout << catan.getPlayerName(n) <<" choose where you want your second settlement" << endl;
        int verNumNew = input[j];
        j++;
        catan.placeSettelemntFirst(verNumNew, n);

    }

    catan.getCards();
    cout << endl;
    catan.cardStutus();
    cout << endl;
    catan.pointStutus();
    cout << endl;

    system("gnome-terminal -- bash -c 'cat mypipe; exec bash'");
    std::ofstream pipe("mypipe");
    
    if (pipe.is_open()) {

        pipe << "this is the map of the action you can preform in you'r turn:"<< endl << endl;
        
        pipe << "0 - to finish your turn"<< endl;
        pipe << "1 - new road"<< endl;
        pipe << "2 - new settelment"<< endl;
        pipe << "3 - upgrade settelment to city"<< endl;
        pipe << "4 - buy development card"<< endl;
        pipe << "5 - use development card"<< endl;
        pipe << "6 - cange 4 to 1"<< endl;
        pipe << "7 - use you'r port"<< endl;
        pipe << "8 - switch cards with another player"<< endl;
        pipe << "9 - print the points status"<< endl;
        pipe << "10 - print the cards status"<< endl << endl;

        pipe << "Building Cost:"<< endl <<endl;
        pipe << "Road-             🧱🪵"<< endl;
        pipe << "Settelment-       🧱🪵🌾🐑" << endl;
        pipe << "City-             🌾🌾🪨🪨🪨" << endl;
        pipe << "Development Card- 🌾🐑🪨" << endl;

        pipe.close();
        
    }

    for(int i=0; i<6; i++){
        catan.turn(org);
        org = (org + 1) % 3;
    }

    return 0;
} 







