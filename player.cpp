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
    
    string Player::getName(){
        return this -> name;
    }

    int Player::rollDice(){
        int dice1 = (rand() % 6) + 1;
        int dice2 = (rand() % 6) + 1;
        cout << "roll dice " <<dice1 + dice2 << "  dice #1: " << dice1 << " dice #2: " << dice2 << endl;
        return dice1 + dice2;
    }

    // void Player::trade(Player p2, string give, string get, int amount_give, int amount_get){
    //     // to check if p2 egrea?!?!??!?!?!?!?!?!?!?!?
    // }
    // void Player::endTurn(){
    //     // to check if somone won !!!!!!!!!!!!!!!!!!!!!!!!!!
    // }

    void Player::placeRoad(){
        --structurs[2];
    }

    void Player::buyRoad(){
        --resorce_cards[3];
        --resorce_cards[1];
    }

    void Player::placeSettelemnt(){
        --structurs[0];
        ++points;
    }

    void Player::buySettelment(){
        --resorce_cards[3];
        --resorce_cards[1];
        --resorce_cards[2];
        --resorce_cards[4];
    }

    void Player::buyCity(){
        resorce_cards[0] -= 3;
        resorce_cards[2] -= 2;
    }

    void Player::placeCity(){
        ++structurs[0];
        --structurs[1];
        ++points;
    }
    
    bool Player::canSettel(){ // check if the player hve the resources to settel
        // to add check of 2 roades !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(resorce_cards[1] >= 1 && resorce_cards[2] >= 1 && resorce_cards[3] >= 1 && resorce_cards[4] >= 1){
            return true;
        } 
        return false;
    }

    bool Player::canRoad(){ // check if the player hve the resources to settel
        // to add check of 2 roades !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(resorce_cards[1] >= 1 && resorce_cards[3] >= 1){
            return true;
        } 
        return false;
    }

    bool Player::canCity(){ // check if the player hve the resources to settel
        if(resorce_cards[0] >= 3 && resorce_cards[2] >= 2){
            return true;
        } 
        return false;
    }

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

    void Player::whatsMyCards(){
        cout << name << "'s cards:" << endl;
        cout << "🪨  🧱  🌾  🪵  🐑" << endl;
        cout <<" " << resorce_cards[0] << "   ";
        cout << resorce_cards[1] << "   ";
        cout << resorce_cards[2] << "   ";
        cout << resorce_cards[3] << "   ";
        cout << resorce_cards[4] << endl;
    }


    int Player::getPoints(){
        return points;
    }

    void Player::fourToOne(int from, int to){
        if (resorce_cards[from] >= 4){
            resorce_cards[from] -= 4;
            resorce_cards[to]++;
        }
        else{
            cout << " sory but you cant do this :(" << endl;
        }
    }

    void Player::throwCards(int what, int how){
        if(resorce_cards[what] < how){
            cout << "you chose to many cards" << endl;
        }
        else{
            resorce_cards[what] -= how;
        }
    }

    int Player::numOfCards(){
        return resorce_cards[0] +resorce_cards[1]+ resorce_cards[2]+ resorce_cards[3]+ resorce_cards[4];
    }

    void Player::switchCards(int give, int take){
        resorce_cards[give]--;
        resorce_cards[take]++;
    }
    bool Player::canDo(int what, int how){
        if(resorce_cards[what] >= how){
            return true;
        }
        return false;
    }
}