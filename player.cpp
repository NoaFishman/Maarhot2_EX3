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
        cout << "dice #1: " << dice1 << " dice #2: " << dice2 << endl;
        return dice1 + dice2;
    }

    void Player::trade(Player p2, string give, string get, int amount_give, int amount_get){
        // to check if p2 egrea?!?!??!?!?!?!?!?!?!?!?
    }
    void Player::endTurn(){
        // to check if somone won !!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    void Player::placeRoad(vector<string> places, vector<int> placesNum){

    }

    void Player::placeSettelemnt(){
        structurs[0]--;
        points++;
    }
    
    bool Player::canSettel(){ // check if the player hve the resources to settel
        // to add check of 2 roades !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(resorce_cards[1] >= 1 && resorce_cards[2] >= 1 && resorce_cards[3] >= 1 && resorce_cards[4] >= 1){
            return true;
        } 
        return false;
    }

    void Player::buyDevelopmentCard(){

    }

    void Player::printPoints(){

    }
}