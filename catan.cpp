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
        srand(time(0));
        int randomNumber = std::rand() % 3;
        cout << players[randomNumber].getName() << " is the starting player" << endl;
        return randomNumber;
    }
    
    Board Catan::getBoard(){
        return this-> board;
    }

    bool Catan::isWinner(){
        for(int i=0; i<3; i++){
            if(players[i].getPoints() >= 10){
                cout << "you all loosers " << players[i].getName() << " won!!!" <<endl;
                return true;
            }
        }
        return false;
        
    }

    void Catan::cardStutus(){
        for(int i=0; i<3 ; ++i){
            players[i].whatsMyCards();
        }
    }

    void Catan::placeSettelemnt(int verNum, int n){

        Vertex& curr_ver = board.getVer(verNum);
        Player* p = &players[n];
        int newVer =verNum;

        // check the nighbors !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(board.canBuildSettel(newVer, n, p)){
            players[n].placeSettelemnt();
        }

    }

    void Catan::placeSettelemntFirst(int verNum, int n){

        Vertex& curr_ver = board.getVer(verNum);
        Player* p = &players[n];
        int newVer =verNum;

        // check the nighbors !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        while(!board.canBuildSettelFirst(newVer, n, p)){
            cin >> newVer;
            curr_ver = board.getVer(newVer);
        }
    
        players[n].placeSettelemnt();

    }

    void Catan::placeCity(int verNum, int n){
        Vertex& curr_ver = board.getVer(verNum);
        Player* p = &players[n];

        while(!curr_ver.newCity(p)){
            int newVer;
            cin >> newVer;
            curr_ver = board.getVer(newVer);
        }

        players[n].placeCity();

        // ****************************
    }

    void Catan::placeRoad(int verNum, int verNum2, int n){
        
        Vertex& curr_ver1 = board.getVer(verNum);
        Vertex& curr_ver2 = board.getVer(verNum2);
        while( (!board.canBuildRoad(curr_ver1, curr_ver2, n)) || (!board.newRoad(curr_ver1, curr_ver2, n))){
            cout << "choose the seconde ver agin"<< endl;
            int newVer;
            cin >> newVer;
            curr_ver2 = board.getVer(newVer);
        }

        players[n].placeRoad();
        
    }

    string Catan::getPlayerName(int n){
        return players[n].getName();
    }

    void Catan::getCards(){
        board.getCardsStart();
    }

    void Catan::pointStutus(){
        cout << "points status: "<< endl;
        for(int i=0; i<3 ; ++i){
            cout << players[i].getName() << " have " << players[i].getPoints() << " points" <<endl;
        }
    }

    void Catan::turn(int n){
        cout << endl << players[n].getName() <<"'s turn:"<<endl;
        int dice = players[n].rollDice();
        if(dice == 7){
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            for(int i=0; i<3; i++){
                if(players[i].numOfCards() > 7){
                    int shouldThrow = players[i].numOfCards() / 2;
                    cout << endl;
                    cardStutus();
                    while(shouldThrow > 0){
                        cout << players[i].getName() << " you have more then 7 cards you need to throw "<< shouldThrow << endl;
                        cout << "choose the number of the resours cards you want to change and how many" << endl;
                        cout << "0 - 🪨, 1 - 🧱, 2 - 🌾, 3 - 🪵, 4 - 🐑" << endl;
                        int what, how;
                        cin >> what;
                        cin >> how;
                        players[i].throwCards(what, how);
                        shouldThrow -= how;
                    }
                    
                }
            }
        }
        else{
            board.getCards(dice);
        }
        cout << "choose what you want to do:" << endl;
        int choise =0 ;
        cin >> choise;

        while(choise != 0){
            switch(choise){
                case 0:
                    break;

                case 1:
                    cout << "choose where to place the road" << endl;
                    if(players[n].canRoad()){
                        int v1,v2;
                        cin >> v1;
                        cin >> v2;
                        placeRoad(v1, v2, n);
                        players[n].buyRoad();
                        break;
                    }
                    else{
                        cout << "sorry you dont have enough resourses for a road"<< endl;
                    }
                    break;

                case 2:
                    if(players[n].canSettel()){
                        cout << "choose where to place the setellment" << endl;
                        int v1;
                        cin >> v1;
                        placeSettelemnt(v1, n);
                        players[n].buySettelment();
                        break;
                    }
                    else{
                        cout << "sorry you dont have enough resourses for a settelment"<< endl;
                    }
                    break;

                case 3:
                    if(players[n].canCity()){
                        cout << "choose where the settelment you want to upgade" << endl;
                        int v1;
                        cin >> v1;
                        placeCity(v1, n);
                        players[n].buyCity();
                        break;
                    }
                    else{
                        cout << "sorry you dont have enough resourses for a city"<< endl;
                    }
                    break;

                case 4:
                    break;

                case 5:
                    break;

                case 6:
                    cout << "choose the number of the resours cards you want to change " << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    int from;
                    cin >> from;
                    cout << "choose the number of the resours card to get instade " << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    int to;
                    cin >> to;
                    players[n].fourToOne(from, to);
                    break;

                case 7:
                    break;

                case 8:{
                    cout << "who you wnat to switch cards with?"<< endl;
                    string name1;
                    cin >> name1;
                    int x;
                    bool flag =false;
                    for(int i=0; i<3; i++){
                        string name2 = players[i].getName();
                        if(name2.compare(name1) == 0){
                            x = i;
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        break;
                    }
                    cout << "choose the number of the resours cards you want to give" << endl;
                    cout << "and then the number of the card you want to take" << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    int give, take;
                    cin >> give;
                    cin >> take;
                    cout << name1 << " do you agree to this? y or n" << endl;
                    string ans1;
                    cin >> ans1;
                    if(ans1.compare("n") == 0 ){
                        cout << "sorry " << name1 << " didn't want to swich"<< endl;
                        break;
                    }
                    if(players[n].canDo(give, 1) && players[x].canDo(take, 1)){
                        players[n].switchCards(give, take);
                        players[x].switchCards(take, give);
                    }
                    break;
                    }

                case 9:
                    pointStutus();
                    break;

                case 10:
                    cardStutus();
                    break;
                

            }

            cout << "what you want to do next?" << endl;
            cin >> choise;
        }
        

        
    }

}