

#pragma once
#include <vector>
#include <string>

namespace ariel
{
    class Card{

        char type; //sprades, hearts, diamonds, clubs 
        int value;

        public:

            Card(char, int);
            Card(Card&);
            ~Card();
            int get_value();
            char get_type();
            bool operator == (const Card&) const;
            bool operator > (const Card&) const;
            bool operator < (const Card&) const;

    };
}