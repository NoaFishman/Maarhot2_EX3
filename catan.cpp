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

    RandomInitializer randomInitializer;

    // choose randomly how is starting
    int Catan::ChooseStartingPlayer(){
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

        Player* p = &players[n];

        if(board.canBuildSettel(verNum, n, p)){
            players[n].placeSettelemnt();
            players[n].buySettelment();
        }
        else{
            cout << "sorry you cant settel here" << endl;
        }

    }

    void Catan::placeSettelemntFirst(int verNum, int n){

        //Vertex& curr_ver = board.getVer(verNum);
        Player* p = &players[n];
        int newVer =verNum;

        while(!board.canBuildSettelFirst(newVer, n, p)){
            cout<< "sorry you cant settel here choose new vertex"<<endl;
            cin >> newVer;
            //curr_ver = board.getVer(newVer);
        }
    
        players[n].placeSettelemnt();

    }

    int Catan::getDevCard(){
        srand(time(0));
        int x = rand()%5;
        while(developmentCards[x] == 0){
            x = (x + 1) %5;
        }
        --developmentCards[x];
        return x;
    }

    void Catan::placeCity(int verNum, int n){
        Vertex& curr_ver = board.getVer(verNum);
        Player* p = &players[n];

        while(!curr_ver.newCity(p)){
            int newVer;
            cin >> newVer;
            curr_ver = board.getVer(newVer);
        }

        players[n].buyCity();
    }

    void Catan::placeRoad(int verNum, int verNum2, int n){
        
        // Vertex& curr_ver1 = board.getVer(verNum);
        // Vertex& curr_ver2 = board.getVer(verNum2);
        // while( (!board.canBuildRoad(curr_ver1, curr_ver2, n)) || (!board.newRoad(curr_ver1, curr_ver2, n))){
        //     cout << "curr_ver1 num: " << curr_ver1.getNum() << " curr_ver2 num: " << curr_ver2.getNum() << endl;
        //     cout << "choose 2 ver agin"<< endl;
        //     int newVer;
        //     cin >> newVer;
        //     int xx;
        //     cin >> xx;
        //     curr_ver1 = board.getVer(xx);
        //     curr_ver2 = board.getVer(newVer);
            
        // }

        Vertex* curr_ver1 = &board.getVer(verNum);
        Vertex* curr_ver2 = &board.getVer(verNum2);

        while ((!board.canBuildRoad(*curr_ver1, *curr_ver2, n)) || (!board.newRoad(*curr_ver1, *curr_ver2, n))) {
            cout << "curr_ver1 num: " << curr_ver1->getNum() << " curr_ver2 num: " << curr_ver2->getNum() << endl;
            cout << "choose 2 ver again" << endl;
            int newVer;
            cin >> newVer;
            int xx;
            cin >> xx;
            curr_ver1 = &board.getVer(xx);
            curr_ver2 = &board.getVer(newVer);
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

        // those parameter will help if the player use bless yeard card
        bool blessYear = false;
        int bless1, bless2, amountB1, amountB2;

        if(players[n].totalDevCards() > 0){
            cout <<players[n].getName() << " do you want to use dev card? y/n" << endl;
            string ans;
            cin >> ans;
            if (ans.compare("y") == 0){
                useDevCard(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear);
                if(blessYear){
                    turnChoise(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear);
                }
            }
            else{
                turnChoise(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear);
            }
        
        }
        else{
            turnChoise(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear);
        }
    }

    void Catan::rollDice(int n){
        int dice = players[n].rollDice();
        if(dice == 7){
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
    }

    void Catan::turnChoise(int n, int* bless1, int* bless2, int* amountB1, int* amountB2, bool* blessYear){

        bool devFlag = false;
        cout << endl << players[n].getName() <<"'s turn:"<<endl;
        rollDice(n);
        cout << endl;
        players[n].whatsMyCards();
        
        cout << endl << players[n].getName() << " choose what you want to do:" << endl;
        int choise =0 ;
        cin >> choise;

        while(choise != 0 || *blessYear){
            switch(choise){
                case 0:
                    if(*blessYear == true && (*amountB1 < players[n].getResorceAmont(*bless1) || *amountB2 < players[n].getResorceAmont(*bless2))){

                        cout << "sorry you didn't use all the resorce card from the year of bless card you cant finish you'r turn"<< endl;
                        choise = 10;
                    }
                    else{
                        *blessYear = false;
                        break;
                    }
                    break;

                case 1:
                    cout << "choose where to place the road" << endl;
                    if(players[n].canRoad()){
                        int v1,v2;
                        cin >> v1;
                        cin >> v2;
                        players[n].buyRoad();
                        placeRoad(v1, v2, n);
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
                        break;
                    }
                    else{
                        cout << "sorry you dont have enough resourses for a settelment" << endl;
                    }
                    break;

                case 3:
                    if(players[n].canCity()){
                        cout << "choose where the settelment you want to upgade" << endl;
                        int v1;
                        cin >> v1;
                        placeCity(v1, n);
                        break;
                    }
                    else{
                        cout << "sorry you dont have enough resourses for a city"<< endl;
                    }
                    break;

                case 4:
                    if(players[n].canDevelopCard()){
                        int card = getDevCard();
                        players[n].buyDevelopmentCard();
                        players[n].getDevCard(card);
                        devFlag = true;
                    }
                    break;

                case 5:
                    if(!devFlag){
                        players[n].printDevCards();
                        useDevCard(n, bless1, bless2, amountB1, amountB2, blessYear);
                    }
                    else{
                        cout << "sorry you cant use development card in this turn" << endl;
                    }
                    break;

                case 6:
                    cout << "choose the number of the resours cards you want to change " << endl;
                    cout << "and them the number of the resours card to get instade " << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    int from;
                    cin >> from;
                    int to;
                    cin >> to;
                    players[n].fourToOne(from, to);
                    break;

                case 7:
                    //board.printVer();
                    board.boardStutus();
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
            if(*blessYear == true && *amountB1 >= players[n].getResorceAmont(*bless1) && *amountB2 >= players[n].getResorceAmont(*bless2)){
                *blessYear = false;
                
            }

            cout << endl << players[n].getName() << " what you want to do next?" << endl;
            cin >> choise;
        }
        
    }

    void Catan::useDevCard(int n, int* bless1, int* bless2, int* amountB1, int* amountB2, bool* blessYear){
        cout << "wich develop card do you want to use?" << endl;
        cout << "night - 0, year bless - 2, build two roads - 3, monopol - 4" << endl;
        int x;
        cin >> x;
        if(players[n].haveCard(x)){
            switch(x){
                case 0:{
                    cardStutus();
                    cout << "choose who you want to steal resorce from" << endl;
                    string name;
                    cin >> name;
                    int other;
                    bool flag = false;
                    for(int i=0; i<3; i++){
                        string name2 = players[i].getName();
                        if(name2.compare(name) == 0){
                            other = i;
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        cout << "sorry you chose the wrong name" << endl;
                        break;
                    }
                    cout << endl << "choose the resorce you want to take" << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    int what;
                    cin >> what;
                    players[n].addResoCard(1, what);
                    players[other].throwCards(what, 1);
                    players[n].useDevCard(x);
                    break;
                }
                case 2:{
                    *blessYear = true;
                    cout << "choose 2 resorces, and you have to use them in this turn" << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    cin >> *bless1;
                    cin >> *bless2;
                    int b1 = *bless1;
                    int b2 = *bless2;
                    *amountB1 = players[n].getResorceAmont(b1);
                    *amountB2 = players[n].getResorceAmont(b2);
                    players[n].addResoCard(1, b1);
                    players[n].addResoCard(1, b2);
                    players[n].useDevCard(x);
                    break;
                }
                case 3:{
                    cout << "choose where to place the first road" << endl;
                    int v1,v2;
                    cin >> v1;
                    cin >> v2;
                    placeRoad(v1, v2, n);
                    cout << "choose where to place the seconde road" << endl;
                    cin >> v1;
                    cin >> v2;
                    placeRoad(v1, v2, n);
                    players[n].useDevCard(x);
                    break;
                }
                case 4:{
                    cardStutus();
                    cout << endl << "choose the resorce you want to take from every one" << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    int reso;
                    cin >> reso;
                    int sum=0;
                    for(int i=0; i<3; i++){
                        sum = sum + players[i].takeYourResorce(reso);
                    }
                    players[n].addResoCard(sum, reso);
                    players[n].useDevCard(x);
                    break;
                }
            }
        }
    }

}