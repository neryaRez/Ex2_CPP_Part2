
#include "card.hpp"

using namespace std;

namespace ariel{

    Card::Card(){}


     Card::Card(string s , int i){
    
        this->type = s;
        this->value = i;
        
    }

    // Card::Card(const Card& other) {
    //     this->type = other.get_type();
    //     this->value = other.get_value();
    // }

    // Card::~Card(){}

    string Card::get_type() const{
        return this->type;
    }

    int Card::get_value() const{
        return this->value;
    }

    string Card::toString() const{
        string str = "";

        if (this->value >= 2 && this->value <= 10){
           str += (to_string(this->value) + " of ");  
        }

        else if(this->value == 1){
            str += "Ace of ";
        }

        else if (this->value == 11)
        {
            str+= "Jack of ";
        }

        else if (this->value == 12)
        {
            str+= "Queen of ";
        }
        else if (this->value == 13)
        {
            str+= "King of ";
        }

        str += this->type;

        return str;
        
    }

    bool Card::operator == (const Card& other) const{
        return this->value == other.value;
    }

    bool Card::operator < (const Card& other) const{
        return this->value < other.value;
    }

    bool Card::operator > (const Card& other) const{
       if (this->value == 1){
        return other.value !=2 && other.value !=1;
       } 
       else if (other.value ==1)
       {
        return this->value==2;
       }
       
       return this->value > other.value;
        
    }

}


