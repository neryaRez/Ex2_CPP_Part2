

#pragma once
#include <string>
using namespace std;

namespace ariel
{
    class Card{

        string type; //spades, hearts, diamonds, clubs 
        int value;

        public:

            Card();
            Card(string, int);
            int get_value () const;
            string get_type() const;

            string toString() const;
            bool operator == (const Card&) const;
            bool operator > (const Card&) const;
            bool operator < (const Card&) const;

    };
}
