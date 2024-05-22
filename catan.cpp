/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
using namespace std;

namespace noa{

    // choose randomly how is starting
    int Catan::ChooseStartingPlayer(){
        int randomNumber = std::rand() % 3;
        cout << players[randomNumber].getName() << "is the starting player" << endl;
        return randomNumber;
    }
    
    Board Catan::getBoard(){
        return this-> board;
    }

    void Catan::printWinner(){
        
    }
    void Catan::placeSettelemnt(vector<string> places, vector<int> placesNum, int n){

        if(!players[n].canSettel()){
            cout << " sorry you dont have the resources to settel" << endl;
            return;
        }

        Vertex& curr_ver = board.getVer(places, placesNum);
        // check the nighbors !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        curr_ver.newSettel(n, 1);
        players[n].placeSettelemnt();

    }

    void Catan::placeRoad(vector<string> places, vector<int> placesNum, int n){
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

}