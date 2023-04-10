#pragma once


#include "card.hpp"
using namespace std;

namespace ariel{

    class Player{


        std::string name;
       // std::vector<Card> packet;

        public:

            //Player();
            Player(std::string name);

            ~Player();

            int stacksize();

            int cardesTaken();

    };


}