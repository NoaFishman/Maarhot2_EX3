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

    // to make sure that all the randoms realy randoms (all the mains inhrtence from here)
    RandomInitializer randomInitializer;

    // choose randomly how is starting
    int Catan::ChooseStartingPlayer(){
        int randomNumber = std::rand() % 3;
        cout << players[randomNumber].getName() << " is the starting player" << endl;
        return randomNumber;
    }
    
    // return the board
    Board Catan::getBoard(){
        return board;
    }

    // check for each player if have 10 or more points
    bool Catan::isWinner(){
        for(int i=0; i<3; i++){
            if(players[i].getPoints() >= 10){
                cout << "you all loosers " << players[i].getName() << " won!!!" <<endl;
                return true;
            }
        }
        return false;
    }

    // print the card status for all the players
    void Catan::cardStutus(){
        for(int i=0; i<3 ; ++i){
            players[i].whatsMyCards();
        }
    }

    // check if it is possible to settel and if possible so settel
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

    // for the first 2 round (when settel) the rules are diffrete so ther is seperate function
    void Catan::placeSettelemntFirst(int verNum, int n){

        Player* p = &players[n];
        int newVer =verNum;

        while(!board.canBuildSettelFirst(newVer, n, p)){
            cout<< "sorry you cant settel here choose new vertex"<<endl;
            cin >> newVer;
        }
        players[n].placeSettelemnt();
    }

    // call the 4 to 1 function for the player
    void Catan::fourToOne(int n, int from, int to){
        players[n].fourToOne(from, to);
    }

    // active buy board function on th player
    void Catan::buyRoad(int n){
        players[n].buyRoad();
    }

    // randomlly choose which card to give the player
    int Catan::getDevCard(){
        srand(time(0));
        int x = rand()%5;
        // like in the build board run untill find card that didn't over
        while(developmentCards[x] == 0){
            x = (x + 1) %5;
        }
        --developmentCards[x];
        return x;
    }

    // retur the player
    Player Catan::getPlayer(int n){
        return players[n];
    }

    // check if possible to build city and bil if it is else will ask the player for new vertex 
    // untill will found the right spot
    void Catan::placeCity(int verNum, int n){
        Vertex* curr_ver = &board.getVer(verNum);
        Player* p = &players[n];

        while(!curr_ver->newCity(p)){
            int newVer;
            cin >> newVer;
            curr_ver = &board.getVer(newVer);
        }
        players[n].buyCity();
    }

    // like in the placeCity aove check if possible and build if it is else ask for diffrent roads
    void Catan::placeRoad(int verNum, int verNum2, int n){
        
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

    // return the player name
    string Catan::getPlayerName(int n){
        return players[n].getName();
    }

    // call the get card start in the board class
    void Catan::getCards(){
        board.getCardsStart();
    }

    // print the point status for all of the players
    void Catan::pointStutus(){
        cout << "points status: "<< endl;
        for(int i=0; i<3 ; ++i){
            cout << players[i].getName() << " have " << players[i].getPoints() << " points" <<endl;
        }
    }

    // this is the turn function
    void Catan::turn(int n){

        // those parameter will help if the player use bless yeard card
        bool blessYear = false;
        int bless1, bless2, amountB1, amountB2;

        // if the player have dev cards so he can use them instad of his turn
        if(players[n].totalDevCards() > 0){
            cout <<players[n].getName() << " do you want to use dev card? y/n" << endl;
            string ans;
            cin >> ans;
            if (ans.compare("y") == 0){
                useDevCard(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear);
                if(blessYear){
                    // if the player chose to use year of bless card so he have to use it in this turn so he have turn
                    turnChoise(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear);
                }
            }
            else{
                // if chose not to use dev card so move on to the turn
                turnChoise(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear);
            }
        
        }
        else{
            // if the player don't have dev cards
            turnChoise(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear);
        }
    }

    // roll dice function
    void Catan::rollDice(int n){
        // randimly roll the dice
        int dice = players[n].rollDice();
        // if the dice is 7 so checking if one of the players have more then 7 cards
        if(dice == 7){
            for(int i=0; i<3; i++){
                if(players[i].numOfCards() > 7){
                    // if have more then 7 card so nee to throw half of them 
                    int shouldThrow = players[i].numOfCards() / 2;
                    cout << endl;
                    cardStutus();
                    while(shouldThrow > 0){
                        // asking the player which cards to give up on untill he gave up of all the cards he neeeded to
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
        // update all the players resorce cards they got
        else{
            board.getCards(dice);
        }
    }

    // this function is when the player chossing what to do
    void Catan::turnChoise(int n, int* bless1, int* bless2, int* amountB1, int* amountB2, bool* blessYear){

        // print who's turn it is and which cards he have
        bool devFlag = false;
        cout << endl << players[n].getName() <<"'s turn:"<<endl;
        rollDice(n);
        cout << endl;
        players[n].whatsMyCards();
        
        cout << endl << players[n].getName() << " choose what you want to do:" << endl;
        int choise =0 ;
        cin >> choise;
        // after choosing what to do go in to a loop that do what the player ask for and let him chose agin what to do
        // doing this untill the player choosing to finish his turn
        while(choise != 0 || *blessYear){
            switch(choise){
                case 0:
                // chose to finish the turn but if the player used the year of bless in this turn need to check that he used the cards he took
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
                // the player chose to buy a new road
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
                // the player chose to buy ne settelment
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
                // the player chose to buy new cuty
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
                // the player chose to buy development card
                    if(players[n].canDevelopCard()){
                        int card = getDevCard();
                        players[n].buyDevelopmentCard();
                        players[n].getDevCard(card);
                        devFlag = true;
                    }
                    break;

                case 5:
                // the player chose to use a development card
                    if(!devFlag){
                        players[n].printDevCards();
                        useDevCard(n, bless1, bless2, amountB1, amountB2, blessYear);
                    }
                    else{
                        cout << "sorry you cant use development card in this turn" << endl;
                    }
                    break;

                case 6:
                // the player chose to switch4 of his resorce cards (have to be the same resorce) to 1 other resource
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
                    //the player chose to print the board status
                    board.boardStutus();
                    break;

                case 8:{
                    // the player chose to switch resorce card wit another player
                    cout << "who you wnat to switch cards with?"<< endl;
                    string name1;
                    cin >> name1;
                    int x;
                    bool flag =false;
                    // check that ther is player in this name
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
                    // choosing what cards you want to switch
                    cout << "choose the number of the resours cards you want to give" << endl;
                    cout << "and then the number of the card you want to take" << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    int give, take;
                    cin >> give;
                    cin >> take;
                    // check that the other player agree
                    cout << name1 << " do you agree to this? y or n" << endl;
                    string ans1;
                    cin >> ans1;
                    if(ans1.compare("n") == 0 ){
                        cout << "sorry " << name1 << " didn't want to swich"<< endl;
                        break;
                    }
                    // check if both of the player have the card they want to switch an do the switching
                    if(players[n].canDo(give, 1) && players[x].canDo(take, 1)){
                        players[n].switchCards(give, take);
                        players[x].switchCards(take, give);
                    }
                    break;
                }

                case 9:
                // the player chose to print the point status
                    pointStutus();
                    break;

                case 10:
                // the player chose to print the card status
                    cardStutus();
                    break;
                

            }
            // checking that if the player chose to use the year of bless this turn so he realy used all the resource cards
            if(*blessYear == true && *amountB1 >= players[n].getResorceAmont(*bless1) && *amountB2 >= players[n].getResorceAmont(*bless2)){
                *blessYear = false;
            }

            // asking the player what he want to do next
            cout << endl << players[n].getName() << " what you want to do next?" << endl;
            cin >> choise;
        }
    }

    // thi sfunction is using a dev card
    void Catan::useDevCard(int n, int* bless1, int* bless2, int* amountB1, int* amountB2, bool* blessYear){
        // asking the player which card to use
        cout << "wich develop card do you want to use?" << endl;
        cout << "night - 0, year bless - 2, build two roads - 3, monopol - 4" << endl;
        int x;
        cin >> x;
        // checking that the player realy owne this card
        if(players[n].haveCard(x)){
            switch(x){
                case 0:{
                    // night card- the player can still a resorce card from anothe player
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
                    // after choosing who to still fro the player choosing what to still
                    cout << endl << "choose the resorce you want to take" << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    int what;
                    cin >> what;
                    // do the stilling
                    players[n].addResoCard(1, what);
                    players[other].throwCards(what, 1);
                    players[n].useDevCard(x);
                    break;
                }
                case 2:{
                    // year of bless card - get 2 resorces and have to use them in this turn
                    *blessYear = true;
                    cout << "choose 2 resorces, and you have to use them in this turn" << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    cin >> *bless1;
                    cin >> *bless2;
                    int b1 = *bless1;
                    int b2 = *bless2;
                    // choosing the cards aand check how many from this resorce the player have now
                    // so to check that at the end of the turn he have less cards from thos resources
                    // and, change the bool to tru so the turn wont end until the player use the cards
                    *amountB1 = players[n].getResorceAmont(b1);
                    *amountB2 = players[n].getResorceAmont(b2);
                    players[n].addResoCard(1, b1);
                    players[n].addResoCard(1, b2);
                    players[n].useDevCard(x);
                    break;
                }
                case 3:{
                    // 2 roads- the player get 2 roads and he need to place them
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
                    // monopol- the player can still all the cards of spesific resource that he choosing from all the other players
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

    // this function is acsactlly the same as the last one just instade of ask the user for input it get vectors with the input
    // this function used only in the tests
    void Catan::useDevCardTest(int n, int* bless1, int* bless2, int* amountB1, int* amountB2, bool* blessYear, vector<int> input, vector<string> inputString){
        // asking the player which card to use
        int j =0;
        int is = 0;
        cout << "wich develop card do you want to use?" << endl;
        cout << "night - 0, year bless - 2, build two roads - 3, monopol - 4" << endl;
        int x = input[j];
        j++;
        // checking that the player realy owne this card
        if(players[n].haveCard(x)){
            switch(x){
                case 0:{
                    // night card- the player can still a resorce card from anothe player
                    cardStutus();
                    cout << "choose who you want to steal resorce from" << endl;
                    string name = inputString[is];
                    is++;
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
                    // after choosing who to still fro the player choosing what to still
                    cout << endl << "choose the resorce you want to take" << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    int what = input[j];
                    j++;
                    // do the stilling
                    players[n].addResoCard(1, what);
                    players[other].throwCards(what, 1);
                    players[n].useDevCard(x);
                    break;
                }
                case 2:{
                    // year of bless card - get 2 resorces and have to use them in this turn
                    *blessYear = true;
                    cout << "choose 2 resorces, and you have to use them in this turn" << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    *bless1 = input[j];
                    j++;
                    *bless2 = input[j];
                    j++;
                    int b1 = *bless1;
                    int b2 = *bless2;
                    *amountB1 = players[n].getResorceAmont(b1);
                    *amountB2 = players[n].getResorceAmont(b2);
                    // choosing the cards aand check how many from this resorce the player have now
                    // so to check that at the end of the turn he have less cards from thos resources
                    // and, change the bool to tru so the turn wont end until the player use the cards
                    players[n].addResoCard(1, b1);
                    players[n].addResoCard(1, b2);
                    players[n].useDevCard(x);
                    break;
                }
                case 3:{
                    // 2 roads- the player get 2 roads and he need to place them
                    cout << "choose where to place the first road" << endl;
                    int v1 = input[j];
                    j++;
                    int v2 = input[j];
                    j++;
                    placeRoad(v1, v2, n);
                    cout << "choose where to place the seconde road" << endl;
                    v1 = input[j],
                    j++;
                    v2 = input[j];
                    j++;
                    placeRoad(v1, v2, n);
                    players[n].useDevCard(x);
                    break;
                }
                case 4:{
                    // monopol- the player can still all the cards of spesific resource that he choosing from all the other players
                    cardStutus();
                    cout << endl << "choose the resorce you want to take from every one" << endl;
                    cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                    int reso = input[j];
                    j++;
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
        players[n].printDevCards();
    }

}