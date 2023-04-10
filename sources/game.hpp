#pragma once

#include "player.hpp"


namespace ariel{

   class Game {

    Player p1;
    Player p2;
    //std::vector <string> turns;
    

    public:

        Game(Player&, Player&);

        ~Game();

        void playTurn();

        void playAll();

        void printLastTurn();

        void printWiner();

        void printStats();

        void printLog();

   };
   
}