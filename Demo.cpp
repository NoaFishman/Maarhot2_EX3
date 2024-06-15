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

void turnChoise(int n, int* bless1, int* bless2, int* amountB1, int* amountB2, bool* blessYear, Catan* catan, vector<int> input, int* j){
    
    bool devFlag = false;
    cout << endl << catan->getPlayerName(n) <<"'s turn:"<<endl;
    
    int dice = input[*j];
    cout << "dice: " << input[*j] << endl;
    (*j)++;
    if(dice == 7){
        for(int i=0; i<3; i++){
            if(catan->getPlayer(n).numOfCards() > 7){
                int shouldThrow = catan->getPlayer(n).numOfCards() / 2;
                cout << endl;
                catan->cardStutus();
                while(shouldThrow > 0){
                    cout << catan->getPlayerName(i) << " you have more then 7 cards you need to throw "<< shouldThrow << endl;
                    cout << "choose the number of the resours cards you want to change and how many" << endl;
                    cout << "0 - 🪨, 1 - 🧱, 2 - 🌾, 3 - 🪵, 4 - 🐑" << endl;
                    int what = input[*j];
                    cout << input[*j] << endl;
                    (*j)++;
                    int how = input[*j];
                    cout << input[*j] << endl;
                    (*j)++;
                    catan->getPlayer(i).throwCards(what, how);
                    shouldThrow -= how;
                }
                
            }
        }
    }
    else{
        catan->getBoard().getCards(dice);
    }


    cout << endl;
    catan->getPlayer(n).whatsMyCards();
    
    cout << endl << catan->getPlayerName(n) << " choose what you want to do:" << endl;
    int choise = input[*j];
    cout << input[*j] << endl;
    (*j)++;

    while(choise != 0 || *blessYear){
        switch(choise){
            case 0:
                if(*blessYear == true && (*amountB1 < catan->getPlayer(n).getResorceAmont(*bless1) || *amountB2 < catan->getPlayer(n).getResorceAmont(*bless2))){

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
                if(catan->getPlayer(n).canRoad()){
                    int v1 = input[*j];
                    cout << input[*j] << endl;
                    (*j)++;
                    int v2 = input[*j];
                    cout << input[*j] << endl;
                    (*j)++;
                    catan->buyRoad(n);
                    catan->placeRoad(v1, v2, n);
                    break;
                }
                else{
                    cout << "sorry you dont have enough resourses for a road"<< endl;
                }
                break;

            case 2:
                if(catan->getPlayer(n).canSettel()){
                    cout << "choose where to place the setellment" << endl;
                    int v1 = input[*j];
                    cout << input[*j] << endl;
                    (*j)++;
                    catan->placeSettelemnt(v1, n);
                    break;
                }
                else{
                    cout << "sorry you dont have enough resourses for a settelment" << endl;
                }
                break;

            case 3:
                if(catan->getPlayer(n).canCity()){
                    cout << "choose where the settelment you want to upgade" << endl;
                    int v1 = input[*j];
                    cout << input[*j] << endl;
                    (*j)++;
                    catan->placeCity(v1, n);
                    break;
                }
                else{
                    cout << "sorry you dont have enough resourses for a city"<< endl;
                }
                break;

            case 4:
                if(catan->getPlayer(n).canDevelopCard()){
                    int card = catan->getDevCard();
                    catan->getPlayer(n).buyDevelopmentCard();
                    catan->getPlayer(n).getDevCard(card);
                    devFlag = true;
                }
                break;

            case 5:
                if(!devFlag){
                    catan->getPlayer(n).printDevCards();
                    catan->useDevCard(n, bless1, bless2, amountB1, amountB2, blessYear);
                }
                else{
                    cout << "sorry you cant use development card in this turn" << endl;
                }
                break;

            case 6:{
                cout << "choose the number of the resours cards you want to change " << endl;
                cout << "and them the number of the resours card to get instade " << endl;
                cout << "🪨 -0,  🧱 -1 ,  🌾-2,  🪵 -3,  🐑 -4" << endl;
                int from = input[*j];
                cout << input[*j] << endl;
                (*j)++;
                int to = input[*j];
                cout << input[*j] << endl;
                (*j)++;
                catan->fourToOne(n, from, to);
                break;
            }
            case 7:{
                //board.printVer();
                catan->getBoard().boardStutus();
                break;
            }
            case 8:{
                cout << "who you wnat to switch cards with?"<< endl;
                string name1;
                cin >> name1;
                int x;
                bool flag =false;
                for(int i=0; i<3; i++){
                    string name2 = catan->getPlayerName(i);
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
                int give = input[*j];
                cout << input[*j] << endl;
                (*j)++;
                int take = input[*j];
                cout << input[*j] << endl;
                (*j)++;
                cout << name1 << " do you agree to this? y or n" << endl;
                string ans1;
                cin >> ans1;
                if(ans1.compare("n") == 0 ){
                    cout << "sorry " << name1 << " didn't want to swich"<< endl;
                    break;
                }
                if(catan->getPlayer(n).canDo(give, 1) && catan->getPlayer(x).canDo(take, 1)){
                    catan->getPlayer(n).switchCards(give, take);
                    catan->getPlayer(x).switchCards(take, give);
                }
                break;
            }

            case 9:
                catan->pointStutus();
                break;

            case 10:
                catan->cardStutus();
                break;
            

        }
        if(*blessYear == true && *amountB1 >= catan->getPlayer(n).getResorceAmont(*bless1) && *amountB2 >= catan->getPlayer(n).getResorceAmont(*bless2)){
            *blessYear = false;
            
        }

        cout << endl << catan->getPlayerName(n) << " what you want to do next?" << endl;
        choise = input[*j];
        cout << input[*j] << endl;
        (*j)++;
    }
}


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

    vector<int> input = {7, 5, 18, 25, 39, 40, 35, 40, 20, 25, 26, 44, 6, 5, 37};
    int j = 0;

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

    input = {6, 7, 10, 1, 6, 4, 0, 9, 6, 2, 1, 10, 2, 26, 7, 10, 0, 11, 2, 35, 9, 0, 3, 1, 4, 11, 0, 9, 4, 0, 6, 1, 35, 28, 1, 28, 24, 7, 9, 0};
    j=0;

    n=org;
    for(int i=0; i<6; i++){
        //catan.turn(org);
        
        // those parameter will help if the player use bless yeard card
        bool blessYear = false;
        int bless1, bless2, amountB1, amountB2;

        if(catan.getPlayer(n).totalDevCards() > 0){
            cout <<catan.getPlayerName(n) << " do you want to use dev card? y/n" << endl;
            string ans;
            cin >> ans;
            if (ans.compare("y") == 0){
                catan.useDevCard(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear);
                if(blessYear){
                    turnChoise(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear, &catan, input, &j);
                }
            }
            else{
                turnChoise(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear, &catan, input, &j);
            }
        
        }
        else{
            turnChoise(n, &bless1, &bless2, &amountB1, &amountB2, &blessYear, &catan, input , &j);
        }

        n = (n + 1) % 3;
    }
    cout << "the 2 turne for each player over :)" << endl;

    return 0;
} 


    



