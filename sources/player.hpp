#pragma once


#include "card.hpp"
#include <vector>
#include <stack>
using namespace std;

namespace ariel{

    class Player{


        string name;
        vector<Card> packet;
        int taken;

        public:
             
            Player(string name);

            Player();

            int stacksize();

            int& cardesTaken();

            string getName();

            vector<Card>& get_packet();
            
    };


}