#include "player.hpp"
#include <string>
using namespace std;


namespace ariel{
    

    Player::Player(string s){
        this->name = s;
        
    }

    Player::~Player(){}

    int Player::cardesTaken(){
        return 1;
    }

    int Player::stacksize(){
        return 1;
    }


}

