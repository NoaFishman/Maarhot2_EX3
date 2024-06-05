/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include "player.hpp"
using namespace std;


namespace noa{
    
    // return the player name
    string Player::getName(){
        return this -> name;
    }

    // roll dice by randomlly choose 2 number between 1-6
    int Player::rollDice(){
        int dice1 = (rand() % 6) + 1;
        int dice2 = (rand() % 6) + 1;
        cout << "roll dice " <<dice1 + dice2 << "  dice #1: " << dice1 << " dice #2: " << dice2 << endl;
        return dice1 + dice2;
    }

    // updatee the player after buing the road
    void Player::placeRoad(){
        --structurs[2];
    }

    // buy the road with the resorce cards
    void Player::buyRoad(){
        --resorce_cards[3];
        --resorce_cards[1];
    }

    //  buy the develop card with the resorce cards
    void Player::buyDevelopmentCard(){
        --resorce_cards[0];
        --resorce_cards[2];
        --resorce_cards[4];
    }

    // updatee the player after buing the settelment
    void Player::placeSettelemnt(){
        --structurs[0];
        ++points;
    }

    // buy the settelment with the resorce cards
    void Player::buySettelment(){
        --resorce_cards[3];
        --resorce_cards[1];
        --resorce_cards[2];
        --resorce_cards[4];
    }

    // update the player after buing the city
    void Player::buyCity(){
        resorce_cards[0] -= 3;
        resorce_cards[2] -= 2;
        ++structurs[0];
        --structurs[1];
        ++points;
    }

    // check if the player have the resources for settel and settelments
    bool Player::canSettel(){ 
        if(resorce_cards[1] >= 1 && resorce_cards[2] >= 1 && resorce_cards[3] >= 1 && resorce_cards[4] >= 1 && structurs[0] > 0){
            return true;
        } 
        return false;
    }
    // check if the player have the resources for develop card
    bool Player::canDevelopCard(){ 
        if(resorce_cards[0] >= 1 && resorce_cards[2] >= 1 && resorce_cards[4] >= 1){
            return true;
        } 
        return false;
    }

    // check if the player have the resources for road and roads
    bool Player::canRoad(){ 
        if(resorce_cards[1] >= 1 && resorce_cards[3] >= 1 && structurs[2] > 0){
            return true;
        } 
        return false;
    }

    // check if the player have the resources for city and citys and settelment to upgrad
    bool Player::canCity(){ 
        if(resorce_cards[0] >= 3 && resorce_cards[2] >= 2 && structurs[0] < 5 && structurs[1] > 0){
            return true;
        } 
        return false;
    }

    // chaeck if the player have this dev card
    bool Player::haveCard(int x){
        if(devCards[x]>0){
            return true;
        }
        return false;
    }

    // after take dev card from the pile add it to the player data and tell the player what he got
    void Player::getDevCard(int x){
        ++devCards[x];
        switch(x){
            case 0:
                cout << "you've got a night" << endl;
                if(devCards[0] == 3){
                    cout << "you have he biggest army so you get 2 victory points" << endl;
                    points += 2;
                }
                break;
            case 1:
                cout << "you've got victory point" << endl;
                points++;
                break;
            case 2:
                cout << "you've got year bless card - you can use it from the next turn" << endl;
                break;
            case 3:
                cout << "you've got 2 road - you can use it from the next turn" << endl;
                break;
            case 4:
                cout << "you've got monopol - you can use it from the next turn" << endl;
                break;
        }
    }

    // after rolling the dice update the cards the player got
    void Player::getCards(int build, string resource){
        // 0 = Mountains, 1 = Hills, 2 = Fields, 3 = Forest, 4 = Pasture
        if(resource.compare("🪨") == 0){
            resorce_cards[0] = resorce_cards[0] +build;
            cout << name << " gets " << build << " 🪨 "<< endl;
        }
        else if(resource.compare("🧱") == 0){
            resorce_cards[1] = resorce_cards[1] +build;
            cout << name << " gets " << build << " 🧱 "<< endl;
        }
        else if(resource.compare("🌾") == 0){
            resorce_cards[2] = resorce_cards[2] +build;
            cout << name << " gets " << build << " 🌾 "<< endl;
        }
        else if(resource.compare("🪵") == 0){
            resorce_cards[3] = resorce_cards[3] +build;
            cout << name << " gets " << build << " 🪵 "<< endl;
        }
        else if(resource.compare("🐑") == 0){
            resorce_cards[4] = resorce_cards[4] +build;
            cout << name << " gets " << build << " 🐑 "<< endl;
        }
    }

    // print the player resorce card at this mpment
    void Player::whatsMyCards(){
        cout << name << "'s cards:" << endl;
        cout << "🪨  🧱  🌾  🪵  🐑" << endl;
        cout <<" " << resorce_cards[0] << "   ";
        cout << resorce_cards[1] << "   ";
        cout << resorce_cards[2] << "   ";
        cout << resorce_cards[3] << "   ";
        cout << resorce_cards[4] << endl;
    }

    // return the number of pints the player have
    int Player::getPoints(){
        return points;
    }

    // update that the player use the dev card
    void Player::useDevCard(int x){
        --devCards[x];
        if(x == 0 && devCards[0] == 2){
            points -= 2;
            cout << "you don't have the biggest army anymor" << endl;
        }
    }

    // return the amount of the spesific resorce the player have
    int Player::getResorceAmont(int reso){
        return resorce_cards[reso];
    }

    // add all the chosen resorce from all the players to this player
    void Player::addResoCard(int how, int what){
        resorce_cards[what] += how;
    }

    // print the player dev cards
    void Player::printDevCards(){
        cout << "  night  V-points  bless-year  two-road  monopol" << endl;
        for(int i=0; i<5; i++){
            cout << "    " << devCards[i] <<"     " ;
        }
        cout << endl;
    }

    // return tha total amount of dev cards the player have
    int Player::totalDevCards(){
        int sum=0;
        for (int i=0; i<5; i++){
            sum = sum + devCards[i];
        }
        return sum;
    }

    // take all the resorce the player chose from all the players
    int Player::takeYourResorce(int reso){
        int ans = resorce_cards[reso];
        resorce_cards[reso] = 0;
        return ans;
    }

    // replace 4 resorce cards with 1 other resorce card
    void Player::fourToOne(int from, int to){
        if (resorce_cards[from] >= 4){
            resorce_cards[from] -= 4;
            resorce_cards[to]++;
        }
        else{
            cout << " sory but you cant do this :(" << endl;
        }
    }

    // when the dice is 7 and you have to many cards, so get read of the card the player chose
    void Player::throwCards(int what, int how){
        if(resorce_cards[what] < how){
            cout << "you chose to many cards" << endl;
        }
        else{
            resorce_cards[what] -= how;
        }
    }
    
    // retur the total number of resorce card the player have
    int Player::numOfCards(){
        return resorce_cards[0] +resorce_cards[1]+ resorce_cards[2]+ resorce_cards[3]+ resorce_cards[4];
    }

    // swiching card with another player
    void Player::switchCards(int give, int take){
        resorce_cards[give]--;
        resorce_cards[take]++;
    }

    // chack if the player can do swich cards with the card he chose
    bool Player::canDo(int what, int how){
        if(resorce_cards[what] >= how){
            return true;
        }
        return false;
    }
}