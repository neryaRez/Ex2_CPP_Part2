
#include "card.hpp"

using namespace std;

namespace ariel{
     Card::Card(char s , int i){
    
        this->type = s;
        this->value = i;
        
    }

    Card::Card(Card& other){
        this->type = other.get_type();
        this->value = other.get_value();
    }

    Card::~Card(){}

    char Card::get_type(){
        return this->type;
    }

    int Card::get_value(){
        return this->value;
    }

    bool Card::operator == (const Card& other) const{
        return this->value == other.value;
    }

    bool Card::operator < (const Card& other) const{
        return this->value < other.value;
    }

    bool Card::operator > (const Card& other) const{
        return this->value > other.value;
    }

}


