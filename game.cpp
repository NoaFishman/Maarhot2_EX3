/**
 * the main file for the game
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
    string name1, name2, name3;
    cout << "welcome to the catan game, lets get started..." << endl;
    cout << "please enter the names of the 3 players: " << endl;
    // get the names from the user
    cin >> name1;
    cin >> name2;
    cin >> name3;
    // create 3 players with the names i got
    Player p1(name1);
    Player p2(name2);
    Player p3(name3);
    // create the board and start the game
    Catan catan(p1, p2, p3);
    int n = catan.ChooseStartingPlayer();
    int org = n;

    for(int i=0; i<3; i++){

        cout << i+1 <<"st player choose where you want to put your first settlement" << endl;
        string where;
        int where_num;
        vector<string> places;
        vector<int> placesNum;
        while(cin >> where){
            places.push_back(where);
        }
        while(cin >> where_num){
            placesNum.push_back(where_num);
        }
        catan.placeSettelemnt(places,placesNum, n);

        cout << i+1 <<"st player choose where you want to put your first road" << endl;
        vector<string> placesR;
        vector<int> placesNumR;
         while(cin >> where){
            placesR.push_back(where);
        }
        while(cin >> where_num){
            placesNumR.push_back(where_num);
        }
        catan.placeRoad(placesR,placesNumR, n);

        n = (n + 1) %3;
    }

    for(int i=0; i<3; i++){
        string where;
        int where_num;
        n = (n - 1) %3;

        cout << i+1 <<"st player choose where you want to put your seconde road" << endl;
        vector<string> placesR;
        vector<int> placesNumR;
         while(cin >> where){
            placesR.push_back(where);
        }
        while(cin >> where_num){
            placesNumR.push_back(where_num);
        }
        catan.placeRoad(placesR,placesNumR, n);

        cout << i+1 <<"st player choose where you want to put your seconde settlement" << endl;
        vector<string> places;
        vector<int> placesNum;
        while(cin >> where){
            places.push_back(where);
        }
        while(cin >> where_num){
            placesNum.push_back(where_num);
        }
        catan.placeSettelemnt(places,placesNum, n);
        
    }
    













}