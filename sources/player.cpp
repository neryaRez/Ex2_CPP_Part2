

#include "player.hpp"
#include <string>
#include <vector>
using namespace std;


namespace ariel{
    
    Player::Player(){}

    Player::Player(string s){
        this->name = s;
        this->taken = 0;
        
    }

    int& Player::cardesTaken(){
        return this->taken;
    }

    int Player::stacksize(){
        return (int)this->packet.size();
    }

    string Player::getName(){
        return this->name;
    }

    vector<Card> & Player::get_packet(){
        return this->packet;
    }


}

